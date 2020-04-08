using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Task2CSharp
{
    public class SystemOfLinearEquation
    {
        private int n;
        private List<LinearEquation> listofcoef = new List<LinearEquation>();
        public SystemOfLinearEquation(int n1)
        {
            this.n = n1;
        }
        public LinearEquation this[int index]
        {
            get
            {
                if (index < 0 || index > size) throw new IndexOutOfRangeException();
                else return listofcoef[index];
            }
            set
            {
                if (index < 0 || index > size) throw new IndexOutOfRangeException();
                else listofcoef[index] = value;
            }
        }
        public void StepConvert()
        {
            int step;
            int j;
            double step1, step2;
            for (int i = 0; i < size; i++)
            {
                j = i;
                if (listofcoef[i][j] == 0)
                {
                    while (listofcoef[i][j] == 0 && j < n) j++;
                    step = 1;
                    while (i + step < size && listofcoef[i + step][j] == 0) step++;
                    if (i + step == size) return;
                    LinearEquation c = new LinearEquation(listofcoef[i]);
                    c = listofcoef[i];
                    listofcoef[i] = listofcoef[i + step];
                    listofcoef[i + step] = c;
                }
                for (int k = i + 1; k < size; k++)
                {
                    step1 = listofcoef[i][j];
                    step2 = listofcoef[k][j];
                    listofcoef[k] *= step1;
                    listofcoef[k] -= listofcoef[i] * step2;
                }
            }
        }
        public double[] GaussMethod()
        {
            while (listofcoef[size - 1].IsEmpty()) listofcoef.RemoveAt(size - 1);
            if (listofcoef[size - 1])
            {
                if (size == n)
                {
                    double[] Gauss = new double[n];
                    for (int i = size - 1; i >= 0; i--)
                    {
                        Gauss[i] = listofcoef[i][n];
                        for (int j = i + 1; j < n; j++) Gauss[i] -= listofcoef[i][j] * Gauss[j];
                        Gauss[i] /= listofcoef[i][i];
                    }
                    return Gauss;
                }
                else throw new ArgumentException("Все коэффициенты равны нулю");
            }
            else throw new ArgumentException("Система не имеет решений");
        }
        public override string ToString()
        {
            string s = "";
            for (int i = 0; i < size; i++)
            {
                s += listofcoef[i].ToString();
                s += "\n";
            }
            return s;
        }
        public void Add(LinearEquation a)
        {
            if (a.size == n + 1) listofcoef.Add(a);
            else throw new ArgumentException();
        }
        public int size => listofcoef.Count;
    }
}
