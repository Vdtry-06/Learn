package Code_PTIT.File_Input_And_Output.J07038;

public class Business {
    private String id, name;
    private int amount;
    public Business(String id, String name, int amount) {
        this.id = id;
        this.name = name;
        this.amount = amount;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAmount() {
        return amount;
    }

    @Override
    public String toString() {
        return name;
    }
}
