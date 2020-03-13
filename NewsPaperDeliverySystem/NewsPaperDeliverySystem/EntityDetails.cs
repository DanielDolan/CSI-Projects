using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewsPaperDeliverySystem
{
   public class EntityDetails
    {



        private string firstName;
        private string lastName;
        private string address;
        private string phoneNumber;

        public EntityDetails() { }

        public EntityDetails(string fName,string lName,string addressIn,string phoneNumIn)
        {
            FirstName = fName;
            LastName = lName;
            Address = addressIn;
            phoneNumber = phoneNumIn;
        }



      //  public string FirstName { get; set; }

        public string PhoneNumber
        {
            get
            {
                return phoneNumber;
            }

            set
            {
                phoneNumber = value;
            }
        }

        public string FirstName 
        {
            get
            {
                return firstName;
            }
            set
            {
                firstName = value;
            }
        }
        
        public string LastName
        {
            get {
                return lastName;
                }
            set
            {
                lastName = value;
            }
        }
            
        public string Address
        {
            get
            {
                return address;
            }
            set
            {
                address = value;
            }
        }


        public override string ToString()
        {
            return FirstName + " " + LastName + " " + Address;
        }



    }

}
