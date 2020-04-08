using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Task2CSharp
{
    public class LinearEquation
    {
        private List<double> listofcoef = new List<double>();
        public LinearEquation(double[] array)
        {
            this.listofcoef = array.ToList();
        }
        public LinearEquation(List<double> list)
        {
            this.listofcoef = list.ToList();
        }
        public int size => listofcoef.Count;
        public LinearEquation(string s)
        {
            string[] s1 = Regex.Split(s, @"[^\d\.-]");
            for (int i = 0; i < s1.Length; i++)
            {
                if (s1[i] != "")
                {
                    s1[i] = s1[i].Replace('.',',');
                    listofcoef.Add(double.Parse(s1[i]));
                }
            }
        }
        public LinearEquation(int n)
        {
            if (n < 0) throw new ArgumentException();
            else
            {
                listofcoef = new List<double>();
                for (int i = 0; i < n; i++) listofcoef.Add(0);
            }
        }
        public void Input()
        {
            Random Rand = new Random();
            for (int i = 0; i < size; i++)
            {
                listofcoef[i] = 10 * Rand.NextDouble();
            }
        }
        public void Input(double n)
        {
            for (int i = 0; i < size; i++)
            {
                listofcoef[i] = n;
            }
        }
        public bool IsEmpty()
        {
            for (int i = 0; i < size; i++)
            {
                if (listofcoef[i] != 0) return false;
            }
            return true;
        }
        public double this[int ind]
        {
            get
            {
                if (ind < 0 || ind > size) throw new IndexOutOfRangeException();
                else return listofcoef[ind];
            }
            set
            {
                if (ind < 0 || ind > size) throw new IndexOutOfRangeException();
                else listofcoef[ind] = value;
            }
        }
        public static LinearEquation operator +(LinearEquation a, LinearEquation b)
        {
            LinearEquation a1 = new LinearEquation(a.listofcoef);
            for (int i = 0; i < a.size; i++) a1[i] = a[i];
            for (int i = 0; i < Math.Min(a.size, b.size); i++)
            {
                a1[i] += b.listofcoef[i];
            }
            return new LinearEquation(a1);
        }
        public static LinearEquation operator -(LinearEquation a, LinearEquation b)
        {
            LinearEquation a1 = new LinearEquation(a.listofcoef);
            for (int i = 0; i < a.size; i++) a1[i] = a[i];
            for (int i = 0; i < Math.Min(a.size, b.size); i++)
            {
                a1[i] -= b.listofcoef[i];
            }
            return new LinearEquation(a1);
        }
        public static LinearEquation operator *(LinearEquation a, double r)
        {
            List<double> a1 = new List<double>();
            for (int i = 0; i < a.size; i++) a1.Add(a[i] * r);
            return new LinearEquation(a1);
        }
        public static LinearEquation operator *(double r, LinearEquation a)
        {
            return a * r;
        }
        public static LinearEquation operator -(LinearEquation a)
        {
            List<double> a1 = new List<double>();
            for (int i = 0; i < a.size; i++) a1.Add(a[i]);
            for (int i = 0; i < a.size; i++)
            {
                a1[i] *= (-1);
            }
            return new LinearEquation(a1);
        }
        public static bool operator ==(LinearEquation a, LinearEquation b)
        {
            return a.Equals(b);
        }
        public static bool operator !=(LinearEquation a, LinearEquation b)
        {
            return !(a == b);
        }
        public static bool operator false(LinearEquation a)
        {
            if (a) return false;
            else return true;
        }
        public static bool operator true(LinearEquation a)
        {
            int count = 0;
            for (int i = 0; i < a.size - 1; i++)
            {
                if (a.listofcoef[i] != 0) return true;
                else count++;
            }
            if (count <= a.size - 1 && a.listofcoef[a.size - 1] == 0 || a.listofcoef[a.size - 1] != 0) return false;
            else return true;
        }
        public override string ToString()
        {
            string s = "";
            int i;
            for (i = 0; i < size - 2; i++)
            {
                if (listofcoef[i + 1] >= 0)
                {
                    s += listofcoef.ToString() + 'x' + (i + 1).ToString() + '+';
                }
                else s += listofcoef.ToString() + 'x' + (i + 1).ToString();
            }
            s += listofcoef[i].ToString() + 'x' + (i + 1).ToString();
            s += '=' + listofcoef[size - 1].ToString();
            return s;
        }
        public static implicit operator double[] (LinearEquation a)
        {
            return a.listofcoef.ToArray();
        }
        public override bool Equals(object obj)
        {
            LinearEquation a = (LinearEquation)obj;
            for (int i = 0; i < size; i++)
            {
                if (Math.Abs(listofcoef[i] - a[i])>0.000000001) return false; //17
            }
            return true;
        }
    }
    
}
