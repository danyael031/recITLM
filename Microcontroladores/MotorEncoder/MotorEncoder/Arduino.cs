using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace AplicacionPLC
{
    public class Arduino// agregar los actuadores y modificar el puerto data received y el comprobar data
    {
        #region Delegado y Eventos
        public delegate void DelegadoDataReceived(Arduino sender, EventArgs args);
        public event DelegadoDataReceived DataReceived;
        #endregion
        /* 
         puerto serial
          nombre de puerto
          temperatura
          humedad
          métodos de Métodos lee la iniformación - obtener las variables y asignarlas a los miembros temperatura y humedad
          Evento se dispara cuando se lee correctamente un nuevo dato
        */
        public Arduino()
        {

        }
        private EventArgs e;
        public SerialPort puerto = new SerialPort();
        private string nombrePuerto;
        private double distancia;
        private double temperatura;
        private double humedad;
        private double gas;
        private double luz;
        private string nombreArduino;
        private bool isConected=false;
        private bool buzzer=false;
        private bool actuador1=false;
        private bool actuador2=false;

        #region Propiedades
        public string NombrePuerto
        {
            get { return nombrePuerto; }
            set { nombrePuerto = value; }
        }

        public double Temperatura
        {
            get
            {
                return temperatura;
            }

            set
            {
                if(value >=0 && value <= 80)
                { temperatura = value; }
                
            }
        }

        public double Humedad
        {
            get
            {
                return humedad;
            }

            set
            {
                if(value >=0 && value <= 95)
                {
                    humedad = value;
                }
                
            }
        }

        public bool IsConected
        {
            get
            {
                return isConected;
            }

            set
            {
                isConected = value;
            }
        }

        public double Distancia
        {
            get
            {
                return distancia;
            }

            set
            {
                distancia = value;
            }
        }

        public double Luz
        {
            get
            {
                return luz;
            }

            set
            {
                luz = value;
            }
        }

        public string NombreArduino
        {
            get
            {
                return nombreArduino;
            }

            set
            {
                nombreArduino = value;
            }
        }

        public bool Buzzer
        {
            get
            {
                return buzzer;
            }

            set
            {
                buzzer = value;
            }
        }

        public bool Actuador1
        {
            get
            {
                return actuador1;
            }

            set
            {
                actuador1 = value;
            }
        }

        public bool Actuador2
        {
            get
            {
                return actuador2;
            }

            set
            {
                actuador2 = value;
            }
        }

        public double Gas { get => gas; set => gas = value; }
        #endregion Fin Propiedades

        #region Metodos
        public bool Conectar(string PortName, int BaudRate)
        {
            try
            {
                if (!puerto.IsOpen)
                {

                    puerto.PortName = PortName;
                    puerto.BaudRate = BaudRate;
                    puerto.Open();
                    puerto.DataReceived += Puerto_DataReceived;
                    IsConected = true;
                    return true;
                }
                else
                {
                    return true;
                }
            }
            catch
            {
                return false;
            }


        }
        public bool Desconectar()
        {
            try
            {
                if (isConected)
                {
                    puerto.Close();
                    puerto.Dispose();
                    puerto.DataReceived -= Puerto_DataReceived;
                    isConected = false;
                    return true;
                }
                else
                {
                    return true;
                }
            }
            catch
            {
                return false;
            }
            

        }
        /// <summary>
        /// Comprueba que un string es compatible con el formato de mensaje guarda los valores obtenidos en el objeto
        /// </summary>
        /// <param name="data">String para comprobar y guardar</param>
        /// <returns></returns>
        public bool TestData(string data)
        {
            string[] datatest;
            if (ComprobarData(data, out datatest))
            {
                Temperatura = Convert.ToDouble(datatest[3]);
                Humedad = Convert.ToDouble(datatest[2]);
                return true;
            }
            else
            {
                return false;
            }
            
        }
        /// <summary>
        /// Comprueba que el string tenga el formato correcto.
        /// </summary>
        /// <param name="data">Mensaje a comprobar</param>
        /// <param name="dataSplit">Arreglo que se entrega si el formato es correcto</param>
        /// <param name="numDatos">Cantidad de datos que se van a recivir</param>
        /// <returns></returns>
        public static bool ComprobarData(string data, int numDatos, out string[] dataSplit)// comprueba que los valores ingresados el en mensaje sean correctos y entrega un arreglo string
        {
            double basura = 0;
            string[] elementosMensaje = data.Split('/');
            if (
                elementosMensaje[0]== "~" &&
                elementosMensaje.Length == numDatos + 2
                )                
            {
                dataSplit = elementosMensaje;
                return true;
            }
            else
            {
                dataSplit = null;
                return false;
            }
        }
        public void EnviarComando(string Comando)
        {
            if (isConected)
            {

                puerto.Write(Comando);
                //if (Comando == "50")//El comando 50 es para solicitar la informacion de los sensores y los actuadores
                //{
                //    puerto.WriteLine("~/" + PC + "/" + Comando + "/\n");//aquí se manda una linea de texto al arduino para que el arduino responda con la información de los actuadores
                //}
                //else if (Comando == "51")//El comando 51 es para modificar los actuadores y solicita la información de los sensores
                //{
                //    int bu, ac1, ac2;
                //    if (Buzzer)//no le puedo mandar un true o un false al arduino así que cree variables enteras para mandar un 0 o un 1
                //        bu = 1;// este va a ser el valor que le mandaré a arduino
                //    else
                //        bu = 0;
                //    if (Actuador1)
                //        ac1 = 1;
                //    else
                //        ac1 = 0;
                //    if (Actuador2)
                //        ac2 = 1;
                //    else
                //        ac2 = 0;
                //    // en la siguiente linea se manda la información al arduino que incluye el PC, comando, el buzzer, el actuador1(ventilador) y el actuador2(bomba); los manda separados por diagonales y en el formato que pide el arduino
                //    puerto.WriteLine("~/" + PC + "/" + Comando + "/" + bu + "/" + ac1 + "/" + ac2 + "/\n");
                //}
                //else if (Comando == "desconectar")
                //{
                //    puerto.WriteLine("~/" + PC + "/51/0/0/0/\n");

                //}
            }

        }

        #endregion fin Metodos
        #region eventos
        private void Puerto_DataReceived(object sender, SerialDataReceivedEventArgs e) // agregar los actuadores al arduino
        {
            string mensaje = puerto.ReadTo("\n");
            string[] elementosMensaje;
            if (ComprobarData(mensaje, out elementosMensaje))
            {

            //    NombreArduino = elementosMensaje[1];
                Temperatura = Convert.ToDouble(elementosMensaje[2]);
                Humedad = Convert.ToDouble(elementosMensaje[1]);
            //    Distancia = Convert.ToDouble(elementosMensaje[2]);
            //    Luz = Convert.ToDouble(elementosMensaje[5]);
            
                Gas = Convert.ToDouble(elementosMensaje[3]);
                DataReceived?.Invoke(this, e);
            
            
            //}
            //else
            //{

            }
        }


        #endregion

    }

    
}
