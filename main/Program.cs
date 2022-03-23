using System.Runtime.InteropServices;



namespace main
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            [DllImport("checkVer.dll", EntryPoint = "?checkVer@@YAXXZ", CallingConvention = CallingConvention.Winapi)]
            extern static void checkVer();
            checkVer();
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }
}