using System;
using System.Text;

class Program{
    private delegate void EvHa(int x);
    private static event EvHa evnt;

    static void Main(){
        evnt+=first;
        evnt+=second;

        evnt(4);
    }
    private static void first(int x){
        p("Print" + Convert.ToString(x));
    }
    private static void second(int x){
        p("Print" + Convert.ToString(++x));
    }
    private static void p(string s){
        Console.WriteLine(s);
    }
}
