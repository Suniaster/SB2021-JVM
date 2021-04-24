public class error {
  public static void main(String args[]) {
    int a;

    try {
      try {
        throw new RuntimeException("BBB");
      }
      catch (RuntimeException e) {
        System.out.println("AAAA");
      }
    }
    catch (RuntimeException e) {
      try {
        System.out.println("lindo");
      }
      catch (RuntimeException e1) {
        System.out.println("feio");
      }
    }    
   }
}