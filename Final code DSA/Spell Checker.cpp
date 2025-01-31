#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Header.h"

int main() {

    char con_while = 'c';
    string userInput;
    SpellChecker ob_spellChecker;

    // Insert words into the spell checker
    vector<string> wordsToInsert = {

        /*foods*/"Pizza", "Burger", "Pasta", "Sushi", "Tacos", "Steak", "Salad", "Chicken Wings", "Burrito", "Sandwich", "Fried Rice", "Ice Cream", "Chocolate", "Pancakes", "Waffles", "Cheesecake", "Donuts", "Hot Dog", "French Fries", "Popcorn", "Nachos", "Cupcake", "Ramen", "Soup", "Cereal", "Shrimp Scampi", "Lobster", "Shawarma", "Falafel", "Dim Sum", "Gyros", "Lasagna", "Enchiladas", "Curry", "Tiramisu", "Mango Sticky Rice", "Pretzel", "Cannoli", "Goulash", "Hummus", "Jambalaya", "Risotto", "Pierogi", "Pad Thai", "Mousse", "Escargot", "Crab Cakes", "Baklava", "Ceviche", "Borscht", "Baba Ganoush", "Fajitas", "Hamburger Helper", "Mochi", "Eclairs", "Bagel", "Churros", "Guacamole", "Macarons", "Croissant", "Kebab", "Quiche", "Tofu Stir Fry", "Ratatouille", "Meatball Sub", "Gumbo", "Truffle", "Caviar"
       ,/*fruite*/"Apple", "Banana", "Orange", "Grapes", "Strawberry", "Watermelon", "Mango", "Pineapple", "Kiwi", "Blueberry", "Peach", "Pear", "Cherry", "Plum", "Raspberry", "Blackberry", "Cantaloupe", "Lemon", "Lime", "Avocado", "Coconut", "Pomegranate", "Guava", "Papaya", "Fig", "Date", "Passion Fruit", "Dragon Fruit", "Kiwi", "Lychee", "Melon", "Nectarine", "Cranberry", "Apricot", "Currant", "Gooseberry", "Persimmon", "Pomegranate", "Tangerine", "Rambutan", "Jackfruit", "Star Fruit", "Clementine", "Grapefruit", "Kumquat", "Mandarin", "Mulberry", "Quince", "Soursop", "Sapodilla", "Tamarillo", "Ugli Fruit"
       ,/*profession*/"Doctor", "Teacher", "Engineer", "Programmer", "Nurse", "Artist", "Chef", "Scientist", "Architect", "Police Officer", "Firefighter", "Paramedic", "Writer", "Actor", "Musician", "Athlete", "Pilot", "Photographer", "Journalist", "Lawyer", "Judge", "Librarian", "Farmer", "Dentist", "Psychologist", "Veterinarian", "Electrician", "Plumber", "Carpenter", "Mechanic", "Designer", "Entrepreneur", "Accountant", "Banker", "Economist", "Social Worker", "Therapist", "Dietitian", "Translator", "Meteorologist", "Geologist", "Biologist", "Chemist", "Physicist", "Mathematician", "Statistician", "Sociologist", "Anthropologist", "Historian", "Philosopher", "Philanthropist", "Futurist", "Cartoonist", "Graphic Designer", "Urban Planner", "Environmental Scientist", "Marine Biologist", "Astronomer", "Zoologist", "Botanist", "Paleontologist", "Cryptographer", "Ethicist", "Geneticist"
       ,/*verbs*/"Run", "Jump", "Swim", "Climb", "Fly", "Read", "Write", "Speak", "Listen", "Sing", "Dance", "Eat", "Sleep", "Study", "Learn", "Teach", "Work", "Play", "Laugh", "Cry", "Smile", "Dream", "Think", "Create", "Build", "Destroy", "Explore", "Discover", "Travel", "Cook", "Bake", "Draw", "Paint", "Sculpt", "Compose", "Design", "Code", "Program", "Solve", "Calculate", "Plan", "Organize", "Execute", "Communicate", "Collaborate", "Innovate", "Challenge", "Achieve", "Fail", "Adapt", "Grow", "Change", "Love", "Hate", "Forgive", "Apologize", "Celebrate", "Reflect", "Question", "Answer", "Help", "Support", "Encourage"
       ,/*past verbs*/"Jumped", "Ran", "Slept", "Ate", "Laughed", "Cried", "Played", "Sang", "Danced", "Wrote", "Read", "Built", "Painted", "Saw", "Heard", "Spoke", "Flew", "Swam", "Climbed", "Fell", "Found", "Lost", "Grew", "Shrank", "Broke", "Fixed", "Bought", "Sold", "Taught", "Learned", "Fought", "Won", "Lost", "Drove", "Rode", "Sailed", "Froze", "Melted", "Felt", "Dealt", "Said", "Told", "Thought", "Knew", "Forgot", "Remembered", "Met", "Parted", "Loved", "Hated", "Helped", "Hurt", "Fed", "Starved", "Drank", "Arose", "Fell", "Woke", "Slept", "Bent", "Stood", "Sat", "Lay", "Built", "Destroyed", "Reached", "Missed", "Created", "Desired", "Gave", "Took", "Held", "Released"
       ,/*ajectives*/"Brilliant", "Majestic", "Vibrant", "Graceful", "Swift", "Elegant", "Mysterious", "Adventurous", "Clever", "Colorful", "Playful", "Majestic", "Fierce", "Sleek", "Swift", "Dazzling", "Regal", "Noble", "Vivid", "Gorgeous", "Majestic", "Lively", "Cunning", "Mysterious", "Gentle", "Fascinating", "Stunning", "Intelligent", "Curious", "Daring", "Radiant", "Melodious", "Wise", "Glorious", "Spirited", "Majestic", "Charming", "Energetic", "Vivacious", "Eloquent", "Serene", "Fearless", "Resplendent", "Exquisite", "Gallant", "Enchanting", "Tranquil", "Majestic", "Enigmatic", "Majestic", "Dynamic", "Diligent", "Awe-inspiring", "Marvelous", "Stupendous", "Magnificent", "Dashing", "Glamorous", "Jubilant", "Luminous", "Ethereal", "Majestic", "Gleaming", "Majestic", "Radiant", "Enthralling", "Vivifying", "Lustrous", "Majestic", "Epic", "Majestic", "Panoramic"
       ,/*adberbs*/"Quickly", "Slowly", "Suddenly", "Quietly", "Loudly", "Happily", "Sadly", "Briskly", "Calmly", "Cheerfully", "Sadly", "Joyfully", "Nervously", "Anxiously", "Patiently", "Excitedly", "Carefully", "Eagerly", "Freely", "Warmly", "Coolly", "Awkwardly", "Beautifully", "Effortlessly", "Gently", "Gracefully", "Harshly", "Kindly", "Lazily", "Politely", "Rapidly", "Reluctantly", "Safely", "Shyly", "Thoughtfully", "Unexpectedly", "Willingly", "Wisely", "Yearningly", "Zealously", "Boldly", "Cautiously", "Deliberately", "Honestly", "Intently", "Lively", "Merrily", "Noisily", "Optimistically", "Playfully", "Quirkily", "Ruthlessly", "Swiftly", "Tenderly", "Unabashedly", "Vividly", "Wistfully", "Xenophobically", "Yawningly", "Zestfully"
       ,/*relatives*/"Mother", "Father", "Sister", "Brother", "Aunt", "Uncle", "Cousin", "Grandmother", "Grandfather", "Niece", "Nephew", "Daughter", "Son", "Granddaughter", "Grandson", "Mother-in-law", "Father-in-law", "Sister-in-law", "Brother-in-law", "Aunt-in-law", "Uncle-in-law", "Cousin-in-law", "Stepmother", "Stepfather", "Stepsister", "Stepbrother", "Half-sister", "Half-brother", "Mother's side", "Father's side", "Sister's side", "Brother's side", "Aunt's side", "Uncle's side", "Cousin's side", "In-laws", "Spouse", "Husband", "Wife", "Ex-husband", "Ex-wife", "Partner", "Fiancé", "Fiancée", "Stepdaughter", "Stepson", "Godmother", "Godfather", "Goddaughter", "Godson", "Great-grandmother", "Great-grandfather", "Great-aunt", "Great-uncle", "Great-niece", "Great-nephew", "Mother figure", "Father figure", "Sister figure", "Brother figure", "Aunt figure", "Uncle figure", "Cousin figure"
       ,/*university*/"Semester", "Trimester", "Quarter", "Academic Year", "Course", "Major", "Minor", "Elective", "Prerequisite", "Corequisite", "GPA (Grade Point Average)", "Credit Hour", "Transcript", "Registrar", "Dean", "Professor", "Instructor", "Lecture", "Lab", "Tutorial", "Midterm Exam", "Final Exam", "Thesis", "Dissertation", "Research Paper", "Abstract", "Bibliography", "Peer Review", "Plagiarism", "Citation", "Classroom", "Library", "Student Union", "Residence Hall", "Commencement", "Commencement Speaker", "Alumni", "Undergraduate", "Graduate", "Postgraduate", "Ph.D. (Doctor of Philosophy)", "M.A. (Master of Arts)", "M.S. (Master of Science)", "B.A. (Bachelor of Arts)", "B.S. (Bachelor of Science)", "Academic Advising", "Drop/Add Period", "Withdrawal", "Syllabus", "Orientation", "Graduation Requirements", "Honors Program", "Internship", "Co-op (Cooperative Education)", "Distance Learning", "Online Course", "Thesis Defense", "Graduate School", "Faculty", "Class Schedule", "Tuition", "Financial Aid", "Scholarship", "Fellowship", "Student ID", "Transcript Evaluation", "Student Handbook", "Dean's List"
       
       ,/*animals*/"Dog", "Cat", "Lion", "Tiger", "Elephant", "Giraffe", "Zebra", "Kangaroo", "Panda", "Koala", "Gorilla", "Penguin", "Dolphin", "Killer Whale", "Polar Bear", "Grizzly Bear", "Cheetah", "Leopard", "Hippopotamus", "Rhino", "Koala", "Koala", "Jaguar", "Cheetah", "Giraffe", "Horse", "Donkey", "Camel", "Penguin", "Kangaroo", "Meerkat", "Lemur", "Panda", "Koala", "Kangaroo", "Kangaroo", "Sloth", "Giraffe", "Elephant", "Elephant", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin", "Penguin"
       ,/*birds*/"Eagle", "Hawk", "Owl", "Robin", "Sparrow", "Blue Jay", "Cardinal", "Penguin", "Flamingo", "Pelican", "Hummingbird", "Parrot", "Crow", "Raven", "Swan", "Duck", "Goose", "Pigeon", "Seagull", "Albatross", "Falcon", "Vulture", "Kingfisher", "Woodpecker", "Peacock", "Quail", "Canary", "Finch", "Toucan", "Cockatoo", "Wren", "Cuckoo", "Magpie", "Starling", "Dove", "Warbler", "Swallow", "Ostrich", "Emu", "Cassowary", "Kiwi", "Puffin", "Kookaburra", "Egret", "Snowy Owl", "Tern", "Shoebill", "Condor", "Lark", "Nightingale", "Peregrine Falcon", "Harpy Eagle", "Secretary Bird", "Crowned Crane", "Bald Eagle", "Kea", "Barn Owl", "Red-tailed Hawk", "Budgerigar", "Stork", "Cormorant", "Gull", "Bluebird", "Goldfinch"
       ,/*mathematical*/"Addition", "Subtraction", "Multiplication", "Division", "Sum", "Product", "Quotient", "Factor", "Coefficient", "Variable", "Constant", "Equation", "Inequality", "Expression", "Term", "Factorization", "Exponent", "Radical", "Square Root", "Cube Root", "Absolute Value", "Function", "Domain", "Range", "Coordinate", "Graph", "Axis", "Slope", "Intercept", "Angle", "Triangle", "Rectangle", "Circle", "Sphere", "Cylinder", "Pyramid", "Cone", "Volume", "Area", "Perimeter", "Radius", "Diameter", "Circumference", "Hypotenuse", "Trigonometry", "Sine", "Cosine", "Tangent", "Cotangent", "Secant", "Cosecant", "Derivative", "Integral", "Limit", "Vector", "Matrix", "Determinant", "Eigenvalue", "Eigenvector", "Coefficient Matrix", "System of Equations", "Function Composition", "Logarithm", "Exponential", "Sequence", "Series"
       ,/*geometric*/"Circle", "Square", "Triangle", "Rectangle", "Pentagon", "Hexagon", "Octagon", "Ellipse", "Parallelogram", "Rhombus", "Trapezoid", "Cylinder", "Sphere", "Cube", "Cone", "Pyramid", "Torus", "Dodecagon", "Heptagon", "Decagon", "Nonagon", "Tetrahedron", "Cuboid", "Oval", "Quadrilateral", "Star", "Rhombohedron", "Icosahedron", "Cuboctahedron", "Pentagonal Prism", "Pentagonal Pyramid", "Hexagonal Prism", "Hexagonal Pyramid", "Pentagonal Dipyramid", "Triangular Prism", "Triangular Pyramid", "Square Pyramid", "Square Prism", "Cuboctahedron", "Rhombicuboctahedron", "Rhombicosidodecahedron", "Snub Cube", "Truncated Cube", "Truncated Tetrahedron", "Truncated Dodecahedron", "Truncated Icosahedron", "Truncated Octahedron", "Great Dodecahedron", "Great Icosahedron", "Stellated Dodecahedron", "Stellated Icosahedron", "Small Stellated Dodecahedron", "Great Stellated Dodecahedron", "Dodecagram", "Enneagram", "Decagram", "Pentagram", "Hexagram", "Heptagram", "Octagram", "Nonagram", "Hendecagram", "Dodecagram"
       ,/*devices*/"Laptop", "Desktop Computer", "Smartphone", "Tablet", "Smartwatch", "Fitness Tracker", "Digital Camera", "Smart TV", "Bluetooth Speaker", "Headphones", "Gaming Console", "Router", "Printer", "Scanner", "External Hard Drive", "SSD", "Smart Refrigerator", "Washing Machine", "Dishwasher", "Microwave Oven", "Coffee Maker", "Air Purifier", "Robot Vacuum", "Smart Thermostat", "Smart Light Bulb", "Smart Plug", "Security Camera", "Wireless Mouse", "Mechanical Keyboard", "Graphics Tablet", "E-book Reader", "Portable Charger", "Drone", "VR Headset", "Digital Voice Assistant", "Smart Doorbell", "Action Camera", "Digital Projector", "Bluetooth Earbuds", "Car GPS", "Fitness Smart Scale", "Game Controller", "Portable DVD Player", "Smart Mirror", "Digital Photo Frame", "Electric Toothbrush", "Bluetooth Car Kit", "Raspberry Pi", "GoPro Camera", "Solar Charger", "LED Strip Lights", "Bluetooth Keyboard", "USB Hub", "Smart Lock", "Noise-Canceling Headphones", "Wireless Charging Pad", "Digital Voice Recorder", "Portable Air Conditioner", "Augmented Reality Glasses", "Electric Scooter", "Digital Drawing Tablet", "Network Attached Storage (NAS)", "Home Theater System", "Satellite Phone", "USB-C Docking Station", "Activity Tracker", "Wireless Earphones", "Smart Glasses"

       ,/*sweets*/"Chocolate", "Cupcake", "Brownie", "Cheesecake", "Ice Cream", "Pudding", "Caramel", "Truffle", "Fudge", "Macaron", "Marshmallow", "Tiramisu", "Churro", "Donut", "Eclair", "Gelato", "Baklava", "Cannoli", "Muffin", "Cookie", "Praline", "Gummy Bears", "Toffee", "Lollipop", "Rock Candy", "Cotton Candy", "Jellybean", "Turkish Delight", "Fruitcake", "Strudel", "Mochi", "Peanut Brittle", "Candy Apple", "Honeycomb", "Peanut Butter Cups", "Red Velvet Cake", "Cinnamon Roll", "Maple Syrup", "Cupcake", "Pumpkin Pie", "Creme Brulee", "Banana Split", "Custard", "Rice Pudding", "Candy Cane", "Cherry Pie", "Coconut Macaroon", "Gingerbread", "Peach Cobbler", "Tart", "Sorbet", "Sherbet", "Marzipan", "Halva", "Sufganiyah", "Pralines and Cream", "Pistachio Ice Cream", "Rum Raisin Ice Cream", "Biscotti", "Peanut Butter Fudge", "Strawberry Shortcake", "Raspberry Tart", "Butterscotch", "Jelly Roll", "Angel Food Cake", "Swiss Roll", "Nutella", "Almond Joy", "Nougat"

       ,/*body parts*/"Head", "Neck", "Shoulder", "Arm", "Elbow", "Wrist", "Hand", "Fingers", "Thumb", "Chest", "Back", "Spine", "Waist", "Hip", "Leg", "Thigh", "Knee", "Calf", "Ankle", "Foot", "Toes", "Heel", "Eye", "Eyebrow", "Eyelash", "Ear", "Nose", "Mouth", "Lips", "Tongue", "Teeth", "Jaw", "Chin", "Cheek", "Forehead", "Skull", "Brain", "Hair", "Nail", "Fingertip", "Palm", "Knuckle", "Joint", "Navel", "Belly Button", "Buttocks", "Nape", "Adam's Apple", "Armpit", "Elbow Pit", "Wrist Joint", "Knee Cap", "Shin", "Achilles Tendon", "Sole", "Arch", "Instep", "Palm", "Heel"


    };



    for (const auto& word : wordsToInsert) {
        ob_spellChecker.insertWord(word);
    }

    cout << "WELCOME TO SPELL CHECKER APPLICATION" << endl;
    cout << "------------------------------------" << endl;
    cout << "   CONDIIONS:" << endl;
    cout << "       > FIRST LETTER OF THE WORD SHOLD BE IN UPPER CASE" << endl;
    cout << "       > OTHER LETTERS SHOULD BE IN LOWER CASE" << endl << endl;



    do {


        // Check if a word is in the spell checker
        cout << "ENTER YOUR WORD TO CHECK THE SPELLING: ";
        cin >> userInput;

        // Check if the input is a string with the specified conditions
        bool isValidString = true;

        if (!userInput.empty()) {
            // Check the first letter is uppercase
            if (!isupper(userInput[0])) {
                isValidString = false;
                
            }

            // Check the rest of the letters are lowercase
            for (size_t i = 1; i < userInput.length(); ++i) {
                if (!isalpha(userInput[i]) || !islower(userInput[i])) {
                    isValidString = false;
                    
                }
            }
        }
        else {
            isValidString = false; // Empty input is not considered a string
        }

        if (!isValidString) {
            cout << "!! Please re-enter the word with correct condition to check the spelling." << endl << endl;
            continue;

        }
        



        //search with trie
        string wordToCheck = userInput;
        if (ob_spellChecker.searchWord(wordToCheck)) {
            cout << wordToCheck << " is spelled correctly." << endl;
        }
        else {
            cout << wordToCheck << " is misspelled." << endl;
        }

        cout << endl << "IF YOU WANT TO CONTINUE WITH ANOTHER WORD, PRESS c AND ENTER : " << endl;
        cout << "IF YOU WANT TO QUITE, PRESS q AND ENTER : ";
        cin >> con_while;
        cout << endl;

    } while (con_while != 'q');

    return 0;
};
