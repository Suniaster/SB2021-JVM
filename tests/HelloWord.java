class HelloWord {
  public static void main(String[] s) {
    String ola;

    // instanciação
    ola = new String("Alô Mundo Java !");

    // declaração e instanciação (mais prático)
    ola = "Alô Mundo Java !";
    String nome = "Prof. Omero Francisco Bertol.";

    // concatenação (\n = pula linha)
    String aula = ola + "\nby " + nome;
    System.out.println(aula);
  }
}
