import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner reader = new Scanner(System.in);
		int aa;
		int res;
		int temp;
		aa = reader.nextInt();
		res = 0;temp = 1;
		while(aa != 0)
		{
			res += (aa % 10) * temp;
			temp *= 8;
			aa /= 10;
		}

		System.out.println(res);
	}
}
