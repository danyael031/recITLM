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

namespace Practica6Servo
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

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            arduino1.EnviarComando("~/" + slGrados.Value +"/\n");//toma los grados del slide y los envía
            try
            {
                lbGrados.Content = slGrados.Value.ToString("####0.00");
            }
            catch { }
            
        }

        private void BtConectar_Click(object sender, RoutedEventArgs e)
        {
            if (cbPuerto.SelectedItem != null &&
               !arduino1.IsConected)
            {
                arduino1.Conectar(cbPuerto.SelectedItem.ToString(), 9600);
                if (arduino1.IsConected)
                {
                    //arduino1.DataReceived += Arduino1_DataReceived;
                    
                    btConectar.Content = "Desconectar";
                }
            }
            else if (btConectar.Content.ToString() == "Desconectar" && arduino1.IsConected)
            {
                if (arduino1.Desconectar())
                {
                    //arduino1.DataReceived -= Arduino1_DataReceived;
                    btConectar.Content = "Conectar";

                }
            }
        }

        private void CbPuerto_DropDownOpened(object sender, EventArgs e)
        {
            string[] arregloPuertos = SerialPort.GetPortNames(); //arreglo con los puertos disponibles
            cbPuerto.Items.Clear();
            foreach (string elementoPuerto in arregloPuertos)
            {
                cbPuerto.Items.Add(elementoPuerto);
            }
        }
    }
}
