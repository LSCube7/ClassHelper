using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;
using Microsoft.Win32;

namespace main
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            RegistryKey lc = Registry.CurrentUser.OpenSubKey(@"LSCube\ClassHelper");
            int lcv = 0;
            lcv = (int)lc.GetValue("License");
            if (lcv == 0) Application.Exit(); 
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            [DllImport("recover.dll", EntryPoint = "?recover@@YAXXZ", CallingConvention = CallingConvention.Winapi)]
            extern static void recover();
            recover();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            [DllImport("minimize.dll", EntryPoint = "?minimize@@YAXXZ", CallingConvention = CallingConvention.Winapi)]
            extern static void minimize();
            Thread.Sleep(3000);
            minimize();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string target = "https://github.com/CrystalCarrot777/ClassinHelper/";
            System.Diagnostics.Process.Start(target);
        }

    }
}