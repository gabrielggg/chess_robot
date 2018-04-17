using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
using System.IO;



namespace WindowsFormsApplication1
{

    public partial class Form1 : Form
    {
        
        string Recibirdato;
        int gab = 0;
        int num1;
        int num2;
        string[] casillas = { "x2","a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8", "h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8","o-","o","o-o","-o","a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "c1", "c2", "c3", "x2", "x2", "x2", "c7", "c8", "d1", "d2" };
        public Form1()
        {
            InitializeComponent();
            if (!serialPort1.IsOpen)
            {
                try
                {
                    serialPort1.Open();
                }
                catch(System.Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }
            
            }

            serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.Recibir);



        }

        private void Recibir(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            Recibirdato = this.serialPort1.ReadLine();
            
            this.Invoke(new EventHandler(actualizar));

        }

        private void actualizar(object sender, EventArgs e)
        {
            int y = 1;
            //int gab = 0;
            int IniAN0 = Recibirdato.IndexOf("w");
            int FinAN0 = Recibirdato.IndexOf("x");
            int tamanio = Recibirdato.Length;
            if (Recibirdato.Length > 10)
            {
                Recibirdato = "";
            } 

            textBox1.Text = "";
            //textBox1.Text = ("dato recibido = " + Recibirdato + " posicion de la w en  " + IniAN0 + "posicion de la x en " + FinAN0 + "tamaño" + tamanio);
            
            string[] cas =  Recibirdato.Split(';');
            num1 = int.Parse(cas[0]);
            num2 = int.Parse(cas[1]);
            textBox1.Text = ("dato recibido = " + casillas[num1] + casillas[num2] + " posicion de la w en  " + IniAN0 + "posicion de la x en " + FinAN0 + "tamaño" + tamanio);
                StreamWriter escribir = File.AppendText("E:\\out1.txt");


                escribir.WriteLine(casillas[num1] + casillas[num2]);
            //escribir.WriteLine(casillas[num1]+casillas[num2]);
            //escribir.WriteLine("hola");
             //   if (gab == 8)
              
            //{
            //        StreamWriter escribirA = File.CreateText("E:\\out1.txt");
                    
                   // gab = 0;
              //  }

            escribir.Close();
            Recibirdato = "";

            if (gab == 8)
            {
                StreamWriter escribirA = File.AppendText("E:\\out.txt");
                escribirA.WriteLine(casillas[num1] + casillas[num2]);
                
                escribirA.Close();
                gab = 0;
              //  Thread.Sleep(3000);
                
                
            }
            if (num1 == 88)
            {
                gab = 8;
            }

            if (num1 == 87)
            {
                File.Delete("E:\\out1.txt");
            } 

           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

      
    }
}
