package spract_11;

public class Polic {
    int number;
    String company;
    String surname;

    public Polic(int number, String company, String surname) {
        this.number = number;
        this.company = company;
        this.surname = surname;
    }

    public int getNumber() {
        return number;
    }

    @Override
    public String toString() {
        return "Polic{" +
                "number=" + number +
                ", company='" + company + '\'' +
                ", surname='" + surname + '\'' +
                '}'+"\n";
    }
}
