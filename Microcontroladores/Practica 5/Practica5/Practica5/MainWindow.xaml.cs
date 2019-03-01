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
            ReiniciarAguja();
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
                    btConectar.Content = "Desconectar";
                }
            }
            else if (btConectar.Content.ToString() == "Desconectar" && arduino1.IsConected)
            {
                if (arduino1.Desconectar())
                {
                    arduino1.DataReceived -= Arduino1_DataReceived;
                    btConectar.Content = "Conectar";
                    ReiniciarAguja();
                }
            }
        }

        private void Arduino1_DataReceived(Arduino sender, EventArgs args)
        {
            Action chAguja = () => {
                RotateTransform rt = new RotateTransform(CambiarAguja(arduino1.Gas,100,10000));
                Aguja.RenderTransform = rt;
            };
            Action chLabel = () => {
                lbVal.Content = Convert.ToString(arduino1.Gas);
            };
            Aguja.Dispatcher.Invoke(chAguja);
            lbVal.Dispatcher.Invoke(chLabel);

        }

        private double CambiarAguja(double Val, double LimInf, double LimSup)
        {
            /*
             *hacer los cálculos necesarios para convertir el valor del sensor a la salida de la aguja
             * probablemente sea necesario que la aguja ponga los valores de acuerdo a una funsión logarítmica..
             * aún no tengo ni puta idea de cómo hacerlo
             */
            double rango = LimSup - LimInf;
            double escalon = 270 / rango;

            double grados = ((Val - LimInf )* escalon) - 135;

            return grados;


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

        private void ReiniciarAguja()
        {
            RotateTransform Ri = new RotateTransform(-135);
            Aguja.RenderTransform = Ri;
            lbVal.Content = "0";
            lbVal.HorizontalContentAlignment = HorizontalAlignment.Center;
        }
    }
}
