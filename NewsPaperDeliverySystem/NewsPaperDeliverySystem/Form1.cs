using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO; // using for input and output
using Microsoft.VisualBasic.FileIO;

namespace NewsPaperDeliverySystem
{
    public partial class Form1 : Form
    {
        public static List<Household> houseHoldList = new List<Household>();
        public static List<Carriers> carrierList = new List<Carriers>();
        public static List<Publication> publicationList = new List<Publication>();
        public static  int indexHouse;
        public static int indexCarrier;
        private int recurringFee;




        public Form1()
        {
            InitializeComponent();
            LoadPublications();
            button3.Enabled = false;
            button6.Enabled = false;
            button5.Enabled = false;
            button10.Enabled = false;
            
            button8.Enabled = false;
            button7.Enabled = false;
            button12.Enabled = false;
            button14.Enabled = false;
            button15.Enabled = false;

            //details for listview in pubications
            listView1.View = View.Details;
            listView1.GridLines = true;
            listView1.FullRowSelect = true;
          
            foreach (Publication var in publicationList)
            {
                comboBox1.Items.Add(var.Name);
            
            }
            fillHouseHolds();
            fillCarriers();
            countSubscriptions();
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
       
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AddHousehold fillForm = new AddHousehold();
            fillForm.ShowDialog();
        }



        private void button4_Click(object sender, EventArgs e)
        {

            refreshList1();
        }

       

        // button5 loads the selected household info into fields to be edited
        private void button5_Click(object sender, EventArgs e)
        {
            
            
            indexHouse = listView2.FocusedItem.Index;
            textBox1.Text = houseHoldList[indexHouse].FirstName;
            textBox2.Text = houseHoldList[indexHouse].LastName;
            textBox3.Text = houseHoldList[indexHouse].Address;
            textBox4.Text = houseHoldList[indexHouse].PhoneNumber;
            button6.Enabled = true;

        }

      

        //button6 will save the changes made to the user currecntly selected
        private void button6_Click(object sender, EventArgs e)
        {
            
            houseHoldList[indexHouse].FirstName = textBox1.Text;
            houseHoldList[indexHouse].LastName = textBox2.Text;
            houseHoldList[indexHouse].Address = textBox3.Text;
            houseHoldList[indexHouse].PhoneNumber = textBox4.Text;
            refreshList1();
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
        }

        //function that refreshes list of households
        public void refreshList1()
        {
           
            listView2.Items.Clear();
            foreach (Household var in houseHoldList)
            {
               

                string[] row = { (var.FirstName)+" "+ var.LastName, var.Address , var.PhoneNumber };
                var listViewItem = new ListViewItem(row);
                listView2.Items.Add(listViewItem);

            }
        }


        //function to refresh carriers
        public void refreshList2()
        {
           
            listView3.Items.Clear();
            foreach (Carriers var in carrierList)
            {
        
                string[] row = { (var.FirstName) + " " + var.LastName, var.Address, var.PhoneNumber };
                var listViewItem = new ListViewItem(row);
                listView3.Items.Add(listViewItem);
            }
        }



        //button to load carriers
        private void button11_Click(object sender, EventArgs e)
        {
       
        }

        //load form to add new carrier
        private void button10_Click(object sender, EventArgs e)
        {
            AddCarrier fillForm = new AddCarrier();
            fillForm.ShowDialog();
        }

        //refresh carrier button
        private void button9_Click(object sender, EventArgs e)
        {
            refreshList2();
        }

        //edit carrier selection button
        private void button8_Click(object sender, EventArgs e)
        {
           
            indexCarrier = listView3.FocusedItem.Index;
            textBox8.Text = carrierList[indexCarrier].FirstName;
            textBox7.Text = carrierList[indexCarrier].LastName;
            textBox6.Text = carrierList[indexCarrier].Address;
            textBox5.Text = carrierList[indexCarrier].PhoneNumber;
            button7.Enabled = true;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            indexCarrier = listView3.FocusedItem.Index;
            carrierList[indexCarrier].FirstName  = textBox8.Text ;
            carrierList[indexCarrier].LastName = textBox7.Text;
            carrierList[indexCarrier].Address = textBox6.Text;
            carrierList[indexCarrier].PhoneNumber =textBox5.Text;
            refreshList2();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            
        }

        private void button12_Click_1(object sender, EventArgs e)
        {
            indexHouse = listView2.FocusedItem.Index;
            Console.WriteLine("Delete" + houseHoldList[indexHouse].ToString());
            Console.WriteLine(indexHouse);
            houseHoldList.RemoveAt(indexHouse);
            refreshList1();
      
        }

        private void button13_Click(object sender, EventArgs e)
        {
          
            indexCarrier = listView3.FocusedItem.Index;
            Console.WriteLine("Delete" + carrierList[indexCarrier].ToString());
            Console.WriteLine(indexCarrier);
            carrierList.RemoveAt(indexCarrier);
            refreshList2();

        }

        private void listBox4_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        //loads billing info for currently selected home into billing tab
        private void button14_Click(object sender, EventArgs e)
        {
            this.tabControl3.SelectTab(1);
            BillTabInfo();
           
        }


        private void fillHouseHolds()
        {
            var path = @"HouseholdsFile.csv";
            using (TextFieldParser csvParser = new TextFieldParser(path))
            {
                csvParser.CommentTokens = new string[] { "#" };
                csvParser.SetDelimiters(new string[] { "," });
                csvParser.HasFieldsEnclosedInQuotes = true;

                // Skip the row with the column names
                csvParser.ReadLine();

                while (!csvParser.EndOfData)
                {
                    // Read current line fields, pointer moves to the next line.
                    string[] fields = csvParser.ReadFields();
                    string FirstName = fields[0];
                    string LastName = fields[1];
                    string Address = fields[2];
                    string PhoneNum = fields[3];
                    string balance = fields[4];
                    int y = 0;
                    Int32.TryParse(fields[4], out y);

                    int z = 0;
                    Int32.TryParse(fields[5], out z);
                    Household newHouse = new Household(FirstName, LastName, Address, PhoneNum, y,z);

                    //stores ID of user subscriptions into list within household
                    foreach (string value in fields.Skip(6))
                    {
                        if (value != "")
                        {
                            Console.WriteLine(value);

                            int x = 0;
                            Int32.TryParse(value, out x);
                            newHouse.AddPublication(x);
                        }
                    }


                    //houseHoldList.Add(new Household(FirstName, LastName, Address, PhoneNum));
                    houseHoldList.Add(newHouse);

                }
            }
            refreshList1();
            button3.Enabled = true;
            
        }


        private void fillCarriers()
        {
            var path = @"CarriersFile.csv";
            using (TextFieldParser csvParser = new TextFieldParser(path))
            {
                csvParser.CommentTokens = new string[] { "#" };
                csvParser.SetDelimiters(new string[] { "," });
                csvParser.HasFieldsEnclosedInQuotes = true;

                // Skip the row with the column names
                csvParser.ReadLine();

                while (!csvParser.EndOfData)
                {
                    // Read current line fields, pointer moves to the next line.
                    string[] fields = csvParser.ReadFields();
                    string FirstName = fields[0];
                    string LastName = fields[1];
                    string Address = fields[2];
                    string PhoneNum = fields[3];
                   Carriers addCarr = new Carriers(FirstName, LastName, Address, PhoneNum);
                    

                    //stores ID of user subscriptions into list within household
                    foreach (string value in fields.Skip(4))
                    {
                        if (value != "")
                        {
                            Console.WriteLine(value);

                            int x = 0;
                            Int32.TryParse(value, out x);
                            addCarr.AddHousehold(x);
                        }
                    }

                    carrierList.Add(addCarr);


                }
            }

            refreshList2();
           
            button10.Enabled = true;
        }

        private void LoadPublications()
        {
            var path = @"PublicationsFile.csv";
            using (TextFieldParser csvParser = new TextFieldParser(path))
            {
                csvParser.CommentTokens = new string[] { "#" };
                csvParser.SetDelimiters(new string[] { "," });
                csvParser.HasFieldsEnclosedInQuotes = true;

                // Skip the row with the column names
                csvParser.ReadLine();

                while (!csvParser.EndOfData)
                {
                    // Read current line fields, pointer moves to the next line.
                    string[] fields = csvParser.ReadFields();
                    int id = Int32.Parse(fields[0]);
                    string FirstName = fields[1];
                    string Genre = fields[2];
                    int price = Int32.Parse(fields[3]);
                    Publication newPub = new Publication(id, FirstName, Genre, price);
                    publicationList.Add(newPub);
                }
            }
        }

           public void BillTabInfo()
        {
            // Console.WriteLine(label12.Text = houseHoldList[indexHouse].FirstName + " " + houseHoldList[indexHouse].LastName);
            label12.Text = houseHoldList[listView2.FocusedItem.Index].FirstName + " " + houseHoldList[listView2.FocusedItem.Index].LastName;
            listBox4.Items.Clear();
            recurringFee = 0;
            foreach (int var in houseHoldList[listView2.FocusedItem.Index].subscriptions)
            {

                var myItem = publicationList.Find(item => item.ID == var);
                recurringFee += myItem.Price;
                listBox4.Items.Add(myItem.Name);
               
                Console.WriteLine(myItem.Name);
            }
            label14.Text = "$" + recurringFee.ToString() + ".00";
            label16.Text ="$"+ houseHoldList[listView2.FocusedItem.Index].Balance.ToString()+".00";
        }
        //updates balance based on value in 
        private void button15_Click(object sender, EventArgs e)
        {
            int z = 0;
            Int32.TryParse(textBox9.Text, out z);
            //houseHoldList[listBox2.SelectedIndex].Balance += -z;
            houseHoldList[listView2.FocusedItem.Index].UpdateBalance(z);
            BillTabInfo();
            textBox9.Clear();
        }

        private void button16_Click(object sender, EventArgs e)
        {
            houseHoldList[listView2.FocusedItem.Index].Balance += recurringFee;
            BillTabInfo();
        }
        //adds current subscription to user.
        private void button17_Click(object sender, EventArgs e)
        {
           houseHoldList[listView2.FocusedItem.Index].AddPublication (publicationList[comboBox1.SelectedIndex].ID);
            BillTabInfo();
        }


        public void countSubscriptions()
        {
            Dictionary<int, int> counter = new Dictionary<int, int>();
            

            foreach (Household temp in houseHoldList)
            {
                foreach(int var in temp.subscriptions)
                {
                    if (!counter.ContainsKey(var))
                        counter.Add(var, 1);
                    else
                        counter[var]++;
                }
            }

            foreach(KeyValuePair<int,int> entry in counter)
            {
                foreach(Publication pubTemp in publicationList)
                {
                    if(pubTemp.ID == entry.Key) {

                        int due = pubTemp.Price * entry.Value;
                        string[] row = { (pubTemp.Name), entry.Value.ToString(),"$"+due.ToString()+".00" };
                        var listViewItem = new ListViewItem(row);
                        listView1.Items.Add(listViewItem);
                    }
                }
            }

            
        }

        private void listView2_SelectedIndexChanged(object sender, EventArgs e)
        {
            button5.Enabled = true;
            button12.Enabled = true;
            button14.Enabled = true;
            button15.Enabled = true;
            BillTabInfo();
            Console.WriteLine( listView2.FocusedItem.Index);
        }

        private void listView3_SelectedIndexChanged(object sender, EventArgs e)
        {
            button8.Enabled = true;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            listView1.Items.Clear();
            countSubscriptions();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            string displayValue = "";
            foreach(int value in carrierList[listView3.FocusedItem.Index].houseHoldID)
            {
                foreach(Household var in houseHoldList) 
                {
                    if (var.ID == value)
                    {
                        displayValue += var.ToString() + "\n";
                    }
                }
            }
            MessageBox.Show(displayValue);
        }
    }//end class


}//end namespace
