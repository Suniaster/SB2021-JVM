class FarJump
{
    public static void main(String args[])
    {
        call(0, 1);
    }

    public static void call(int x, int y)
    {
        if (x < y)
        {
            y++;
            y++;

            // ... (10921 times - too much code to post here!)

            y++;
            y++;
        }
        System.out.println(y);
    }

}