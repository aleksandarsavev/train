using System;

namespace Mana
{
    public class Person
    {
        public String Id { get; set; }
        public String Name { get; set; }
        public int Age {get; set; }
        public Person Parent { get; set; }
        public bool Male { get; set; }
    }
}