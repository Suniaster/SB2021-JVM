/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teste_marina;

/**
 *
 * @author gabriel
 */
public class Teste_marina {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      int posicao = 0;
        double numero = 0;
        long tempo = 0;
        long inicio = 0;
        long fim = 0;

            
        for (int i = 0; i < 20; i++) {
            posicao = i + 1;

            inicio = System.nanoTime();

            //numero = iterativo(posicao);
            numero = recursivo(posicao);
            fim = System.nanoTime();

            tempo = (fim - inicio);

            System.out.println("Posição: " + posicao + " - Número: " + numero  + " - Tempo(ns) = " +tempo);
        }
    }

    public static double iterativo(int posicao) {
        double anterior = 0;
        double atual = 1;
        double numero = 0;

        if (posicao == 1) {
            numero = 0;
        } else if (posicao == 2) {
            numero = 1;
        } else {
            for (int i = 3; i <= posicao; i++) {
                numero = anterior + atual;
                anterior = atual;
                atual = numero;
                //System.out.println("P: " + i + " n: " + numero);
            }
        }

        return numero;
    }

    public static double recursivo(int posicao) {
        if (posicao == 1) {
            return 0;
        } else if (posicao == 2) {
            return 1;
        } else {
            return recursivo(posicao - 1) + recursivo(posicao - 2);
        }
    }
}
