public class Workshop {
    public static void main(String[] args) {
      Speaker speaker = new Speaker();
      speaker.setProductDetails("ovosnsJJF", 1500.00);
      speaker.printSpeakerDetails();
      speaker.printProductDetails();
    }
  }
  
  
  
class Car{
// attributes
String type; // Sedan hatch back SUV
String color;
String control; // automatic/manual

// constructor
Car(){
    System.out.println("A new car object is created!");
}
void setCarDetails(String t, String col, String cont)
{
    this.type=t;
    this.color=col;
    this.control=cont;
}
}

class Product
{
    String pID;
    double price;

    Product()
    {
        System.out.println("A new product");
    }
    void setProductDetails(String id, double p)
    {
        this.pID=id;
        this.price=p;
    }
    
    void printProductDetails()
    {
        System.out.println(pID);
        System.out.println(price);
    }
}

class Speaker extends Product 
{
    String type;
    int bassLevel;

    Speaker()
    {
        System.out.println("A new speaker");
    }
    void setSpeakerDetails(String id, double p, String type, int bassLevel)
    {
        this.pID=id;
        this.price=p;
        this.type=type;
        this.bassLevel=bassLevel;
    }

    void printSpeakerDetails()
    {
        System.out.println(type);
        System.out.println(bassLevel);
    }
}

class Basket extends Product
{
    String color;
    String size;

    Basket()
    {
        System.out.println("A new basket");
    }

}