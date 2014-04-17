import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class DECORATE {
	public int GCD(int a, int b) {
		if (b==0) 
			return a;
		return GCD(b,a%b);
	}
	public static void main(String []args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
		s=br.readLine();
		int k=Integer.parseInt(br.readLine());
		String seq=s;
		int seqlen=seq.length();
		List <int> l=new ArrayList<int>();
		int i=0;
		int palLen=0;
		while (i<sqLen){
			if(i>palLen && seq.charAt(i-palLen-1)==seq.charAt(i)){
				palLen+=2;
				i+=1;
				continue;
			}
			l.add(palLen);
			int s=l.length(l)-2;
			int e=s-palLen;
			for(int j=s;j<e;j++){
				int d=j-e-1;
				if(l.charAt(j)==d){
					palLen=d;
					break;
				}
				l.add(min(d,l[j]));
			}
		}
	}
}