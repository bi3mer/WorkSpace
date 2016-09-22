using System;
using System.IO;
using System.Collections;

namespace ForEachVSFor
{
	class MainClass
	{
		public static string[] getForTime(int current)
		{
			// initialize array to loop through
			bool[] arr = new bool[current];

			// Current time
			DateTime dt = DateTime.Now;

			for(int i = 0; i < current ; ++i)
			{
				continue;
			}

			string[] results = new string[2];

			results[0] = GC.GetTotalMemory(true).ToString();
			results[1] = (DateTime.Now - dt).TotalSeconds.ToString();

			// time to run
			return results;
		}

		public static string[] getForEachTime(int current)
		{
			// initialize array to loop through
			bool[] arr = new bool[current];

			// Current time
			DateTime dt = DateTime.Now;

			foreach(bool i in arr)
			{
				continue;
			}

			string[] results = new string[2];

			results[0] = GC.GetTotalMemory(true).ToString();
			results[1] = (DateTime.Now - dt).TotalSeconds.ToString();

			// time to run
			return results;
		}

		public static string removeLastComma(string str)
		{
			return str.TrimEnd(',');
		}

		public static void Main (string[] args)
		{
			int iteration = 1000000;
			int max       = 250000000;

			// Strings to be printed
			string iterCounts    = "";
			string forTimes      = "";
			string forEachTimes  = "";
			string forMemory	 = "";
			string forEachMemory = "";

			for(int current = iteration; current <= max; current += iteration)
			{
				// iterations
				iterCounts += current.ToString() + ",";

				// for
				string[] res = MainClass.getForTime(current);
				forTimes  += res[1] + ",";
				forMemory += res[0] + ","; 

				// foreach
				res = MainClass.getForEachTime(current);
				forEachTimes  += res[1] + ",";
				forEachMemory += res[0] + ",";

				// Collect garbage to guarantee clean run on next iteration
				GC.Collect();
			}

			// write out time results
			using(StreamWriter writetext = new StreamWriter("time.csv"))
			{
				writetext.WriteLine(MainClass.removeLastComma(iterCounts));
				writetext.WriteLine(MainClass.removeLastComma(forTimes));
				writetext.WriteLine(MainClass.removeLastComma(forEachTimes));
			}

			// write out memory results
			using(StreamWriter writetext = new StreamWriter("memory.csv"))
			{
				writetext.WriteLine(MainClass.removeLastComma(iterCounts));
				writetext.WriteLine(MainClass.removeLastComma(forMemory));
				writetext.WriteLine(MainClass.removeLastComma(forEachMemory));
			}
		}
	}
}
