using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewsPaperDeliverySystem
{
    public class Carriers : EntityDetails
    {
        public List<int> houseHoldID = new List<int>();

        public Carriers()
        {

        }

        public Carriers(string fName, string lName, string addressIn,string phoneNum) : base(fName, lName, addressIn,phoneNum)
        {

        }

        public override string ToString()
        {
            return base.ToString() + " Carrier";
        }

        public void AddHousehold(int IDin)
        {
            houseHoldID.Add(IDin);
        }


    }
}
