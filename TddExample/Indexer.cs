using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace TddExample
{
    public class Indexer
    {
        private double[] array1;
        private int beg;
        private int end;
        public int getLength
        {
            get => end - beg + 1;
        }
        /*private void setLength
        {
            set => array.Length = value;
        }*/
        public Indexer(double[] array, int beg, int end)
        {
            if (beg > end || end > array.Length || beg < 0) throw new ArgumentException();
            else
            {
                array1 = array;
                this.beg = beg;
                this.end = end;
            }
        } 
        public double this[int ind]
        {
            get
            {
                if (!IndexCheck(ind)) throw new IndexOutOfRangeException();
                else return array1[ind + beg];
            }
            set
            {
                if (!IndexCheck(ind)) throw new IndexOutOfRangeException();
                array1[ind + beg] = value; 
            }
        }
        bool IndexCheck(int ind)
        {
            if (ind >= array1.Length || ind<0 || ind+beg>=array1.Length) throw new ArgumentException();
            return true;
        }
    }
}
