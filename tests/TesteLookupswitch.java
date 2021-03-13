public class TesteLookupswitch {
	public static void main(String[] args) {
		int result = simpleswitch(1);
        System.out.println(result);
        result = simpleswitch(10);
        System.out.println(result);
        result = simpleswitch(28);
        System.out.println(result);
	}

    public static int simpleswitch(int i) {
       switch (i) {
            case 1:
                return 10;
            case 10:
                return 100;
            default:
                return -42;
       }
    }
}