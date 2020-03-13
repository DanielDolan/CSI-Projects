using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NewsPaperDeliverySystem
{
    public partial class AddCarrier : Form
    {
        public AddCarrier()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fname = textBox1.Text;
            string lname = textBox2.Text;
            string address = textBox3.Text;
            string phone = textBox4.Text;
            Carriers newCarrier = new Carriers(fname, lname, address, phone);
            Form1.carrierList.Add(newCarrier);
            this.Close();

        }
    }
}
