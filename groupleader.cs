using System.Xml.Serialization;

[XmlRoot("GroupLeader")]
public class GroupLeader : Student
{
    [XmlElement("Position")]
    public string position { get; set; }

    [XmlElement("PhoneNumber")]
    public string phone_number { get; set; }

    public GroupLeader() : base()
    {
        position = "";
        phone_number = "";
    }
    
    public GroupLeader(int id, string fname, string sname, int age, string group, string pos, string number) : base(id, fname, sname, age, group)
    {
        position = pos;
        phone_number = number;
    }

    public override void readFromConsole()
    {
        base.readFromConsole();
        Console.WriteLine("Позиция: ");
        position = Console.ReadLine();
        Console.WriteLine("Номер телефона: ");
        phone_number = Console.ReadLine();
    }

    public override void writeToConsole()
    {
        base.writeToConsole();
        Console.WriteLine("Позиция: " + position);
        Console.WriteLine("номер телефона: " + phone_number);
    }

}