package spract_11;

public class Polic {
    int inn;
    String company;
    String surname;

    public Polic(int inn, String company, String surname) {
        this.inn = inn;
        this.company = company;
        this.surname = surname;
    }

    public int getInn() {
        return inn;
    }

    @Override
    public String toString() {
        return "Polic{" +
                "inn=" + inn +
                ", company='" + company + '\'' +
                ", surname='" + surname + '\'' +
                '}'+"\n";
    }
}
