/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teste_java;

/**
 *
 * @author gabriel
 */
public class Teste_java {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
        Teste teste = new Teste();
        teste.setX(2);
        teste.setY(1);
        int valor = teste.difference();
        System.out.println(valor);
       
    }
    
}
