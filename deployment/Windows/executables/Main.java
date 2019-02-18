import java.util.Scanner;
public class Main
{
  public static void main (String[]args)
  {
    Scanner puttingvaluesinside=new Scanner(System.in);
    boolean flag=false;
    if(puttingvaluesinside.nextLine().equals("M")) flag=true;
    double sum=0;
    for(int a=0;a<12;a++)
      for(int b=0;b<12;b++)
    {
      if((b>a)&&(a+b<11)) sum+=puttingvaluesinside.nextDouble();
      else puttingvaluesinside.nextDouble();
    }
    if(flag) System.out.printf("%.1f\n",sum/30.0);
    else System.out.println(sum);
  }
}