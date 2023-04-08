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
				Console.Write("dstProcID ? ");
				string text = Console.ReadLine();
				if (int.TryParse(text, out int dstProcID))
				{
					IntPtr hWnd = GetDstWindow("MyWindowClass", dstProcID);
					if (hWnd != IntPtr.Zero)
					{
						Console.WriteLine("send to hWnd={0:x8}", (uint)hWnd);
						SendMessage(hWnd, WM_APP, (IntPtr)0x11, (IntPtr)0x22);
					}
				}
			}
		}

		static IntPtr GetDstWindow(string className, int dstProcID)
		{
			IntPtr hWnd = IntPtr.Zero;
			while (true)
			{
				hWnd = FindWindowEx(HWND_MESSAGE, hWnd, className, null);
				if (hWnd == IntPtr.Zero)
				{
					break;
				}

				uint threadID = GetWindowThreadProcessId(hWnd, out uint processID);
				if (threadID != 0 && processID == dstProcID)
				{
					return hWnd;
				}
			}

			return IntPtr.Zero;
		}
	}
}
