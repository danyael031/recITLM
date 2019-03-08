using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using AplicacionPLC;
using System.IO.Ports;


namespace Practica5
{
    /// <summary>
    /// Lógica de interacción para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Arduino arduino1 = new Arduino();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Boton_Click(object sender, RoutedEventArgs e)
        {

            if (cbConexion1.SelectedItem != null &&
                !arduino1.IsConected)
            {
                arduino1.Conectar(cbConexion1.SelectedItem.ToString(), 9600);
                if (arduino1.IsConected)
                {
                    arduino1.DataReceived += Arduino1_DataReceived;
                    arduino1.EnviarComando(" ");
                    btConectar.Content = "Desconectar";
                }
            }
            else if (btConectar.Content.ToString() == "Desconectar" && arduino1.IsConected)
            {
                if (arduino1.Desconectar())
                {
                    arduino1.DataReceived -= Arduino1_DataReceived;
                    btConectar.Content = "Conectar";
                    
                    MedidorPPM.ReiniciarAguja();

                }
            }
        }

        private void Arduino1_DataReceived(Arduino sender, EventArgs args)
        {
            Action chAguja = () => {
                MedidorPPM.Valor = arduino1.Gas;
            };
            Action actTemp = () => {
                terTermometro.Value = CalcularIndiceCalor(arduino1.Temperatura, arduino1.Humedad);
            };

            MedidorPPM.Dispatcher.Invoke(chAguja);
            terTermometro.Dispatcher.Invoke(actTemp);


            

        }


        private void CbConexion1_DropDownOpened(object sender, EventArgs e)
        {
            string[] arregloPuertos = SerialPort.GetPortNames(); //arreglo con los puertos disponibles
            cbConexion1.Items.Clear();
            foreach (string elementoPuerto in arregloPuertos)
            {
                cbConexion1.Items.Add(elementoPuerto);
            }
        }

        private double CalcularIndiceCalor(double GradoCentigrados, double R)
        {
            double T = GradoCentigrados * 1.8 + 32;
            double HeatIndex = (-42.379 + (2.04901523 * T) + (10.14333127 * R) - (0.22475541 * T * R) - (6.83783e-3 * T * T) - (5.481717e-2 * R * R) + (1.22874e-3 * T * T * R) + (8.5282e-4 * T * R * R) - (1.99e-6 * T * T * R * R));
            double resultado = (HeatIndex - 32) / 1.8;
            return resultado;
        }

    }
}
