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
    public partial class AddHousehold : Form
    {
        public AddHousehold()
        {
            InitializeComponent();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fname = textBox1.Text;
            string lname = textBox2.Text;
            string address = textBox3.Text;
            string phone = textBox4.Text;
            Household newHousehold = new Household(fname, lname, address,phone);
            Form1.houseHoldList.Add(newHousehold);
            this.Close();
           
        }

      
    }
}
