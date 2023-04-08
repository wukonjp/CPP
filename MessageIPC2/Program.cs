using System;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace MessageIPC2
{
	class Program
	{
		[DllImport("user32.dll")]
		static extern int SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, IntPtr lParam);

		[DllImport("user32.dll")]
		public static extern IntPtr FindWindowEx(IntPtr hPparentWnd, IntPtr hPreviousWnd, string className, string windowText);

		[DllImport("user32.dll")]
		static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

		const uint WM_APP = 0x8000;

		static readonly IntPtr HWND_MESSAGE = new IntPtr(-3);

		static void Main(string[] args)
		{
			while (true)
			{
				Console.Write("dstProcID = ");
				string text = Console.ReadLine();
				if (int.TryParse(text, out int dstProcID))
				{
					try
					{
						IntPtr hWnd = FindWindowEx(HWND_MESSAGE, IntPtr.Zero, "MyWindowClass", null);
						if (hWnd != IntPtr.Zero)
						{
							uint threadID = GetWindowThreadProcessId(hWnd, out uint processID);
							if (processID == dstProcID)
							{
								Console.WriteLine("send to hWnd={0:x8} threadID={1}", (uint)hWnd, threadID);
								SendMessage(hWnd, WM_APP, (IntPtr)0x11, (IntPtr)0x22);
							}
						}
					}
					catch
					{
					}
				}
			}
		}
	}
}
