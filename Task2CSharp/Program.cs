using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 4;
            LinearEquation a = new LinearEquation("4,7.8,9,10,26");
            SystemOfLinearEquation listofcoef = new SystemOfLinearEquation(n);
            listofcoef.Add(new LinearEquation("1, 2, 3, 4, 5"));
            listofcoef.Add(new LinearEquation("3, 5, 7, 9, 11"));
            listofcoef.Add(new LinearEquation("5, 8, 4, 2, -2"));
            listofcoef.Add(new LinearEquation("2, 14, 8, 11, 14"));
            listofcoef.StepConvert();
            double[] Gauss = listofcoef.GaussMethod();
            for (int i = 0; i < Gauss.Length; i++)
            {
                Console.Write("x^");
                Console.Write(i + 1);
                Console.WriteLine("={0}", Gauss[i]);
            }
            Console.ReadKey();
        }
    }
}
