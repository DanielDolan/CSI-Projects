using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CsvHelper;


namespace NewsPaperDeliverySystem
{
    public class Household: EntityDetails
    {
       private int balance;
       public List<int> subscriptions = new List<int>();
        private int id;
    
     public Household(string fName,string lName ,string addressIn,string phoneNum,int balanceIn, int idIN) : base(fName, lName, addressIn,phoneNum)
        {
            balance = balanceIn;
            id = idIN;
        }

        public Household(string fName, string lName, string addressIn, string phoneNum) : base(fName, lName, addressIn, phoneNum)
        {
            balance = 0;
        }

        public int Balance
        {
            get { return balance; }
            set { balance = value; }
        }
        

        public override string ToString()
        {
            return FirstName + " " + LastName + " " + Address;
        }

        public void  AddPublication(int IDin)
        {
            subscriptions.Add(IDin);
        }

        public void UpdateBalance(int paymentIN)
        {
            balance -= paymentIN;
        }

      public int ID
        {
            get { return id; }
            set { id = value; }
        }
       
    }
}
