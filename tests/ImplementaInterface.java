/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author gabriel
 */
public class ImplementaInterface implements Interface{

    @Override
    public int funcaoX(int x) {
        System.out.println(x);
        return x;
    }

    @Override
    public int funcaoY(int y) {
        System.out.println(y);
        return y;
    }
    
}
