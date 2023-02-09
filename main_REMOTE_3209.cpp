#include <iostream>
#include "EmergencyCenter.h"
#include "main.h"
#include "mail.h"


using namespace std;

int main()
{
    /*
     ************************************************************ SCENARIO 3 - Sam ************************************************************
     */

    auto *twig = EmergencyCenter::getInstance();
    auto Galaxy= make_shared<Location>("twix galaxy");
    auto planet1= make_shared<Location>("X AE A-12");
    auto planet2=make_shared<Location>("LV-426");
    auto orange_volcano=make_shared<Location>("redstone");
    auto red_volcano= make_shared<Location>("orangestone");
    auto Moon_unit= make_shared<Location>("Moon Unit");
    auto Dweezil=make_shared<Location>("Dweezil");


    auto sensor_galaxy= make_shared<MotionSensor>("nokia", "twig galaxy");
    auto redstone_smoke= make_shared<SmokeSensor>("alcatel", "red volcano");
    auto orangestone_smoke= make_shared<SmokeSensor>("alcatel", "orange stone");
    auto sensor_planet1 = make_shared<SmokeSensor>("Disney","X AE A-12");
    auto oxygen_sensor= make_shared<SmokeSensor>("samsung", "LV-426");
    auto motion_planet2= make_shared<MotionSensor>("Disney", "LV-426");
    auto motion_dweezil = make_shared<MotionSensor>("Disney", "Dweezil", 20, 8);
    auto motion_moon= make_shared<MotionSensor>("Disney", "Moon Unit",20, 8);
    auto smoke_dweezil= make_shared<SmokeSensor>("Disney", "Dweezil");
    auto smoke_moon= make_shared<SmokeSensor>("Disney", "Moon Unit");


    twig->add(Galaxy);
    twig->addChildToParent(Galaxy, sensor_galaxy);
    twig->addChildToParent(Galaxy, planet1);
    twig->addChildToParent(Galaxy, planet2);


    twig->addChildToParent(planet1, orange_volcano);
    twig->addChildToParent(orange_volcano, orangestone_smoke);

    twig->addChildToParent(planet1, sensor_planet1);
    twig->addChildToParent(planet1, red_volcano);
    twig->addChildToParent(red_volcano, redstone_smoke);

    twig->addChildToParent(planet2, oxygen_sensor);
    twig->addChildToParent(planet2, motion_planet2);

    twig->addChildToParent(planet2, Dweezil);
    twig->addChildToParent(Dweezil, motion_dweezil);
    twig->addChildToParent(Dweezil, smoke_dweezil);

    twig->addChildToParent(planet2, Moon_unit);
    twig->addChildToParent(Moon_unit, motion_moon);
    twig->addChildToParent(Moon_unit, smoke_moon);

    auto peacekeeping_warning= std::make_shared<Mail>("warning", "peacekeeping force");
    sensor_galaxy->addStrategy(peacekeeping_warning);

    auto alarm_planet1 = std::make_shared<Alarm>("X AE A-12");
    auto scientist_warning = std::make_shared<Mail>(" Eletronic message", "Scientists");
    sensor_planet1->addStrategy(scientist_warning);
    sensor_planet1->addStrategy(alarm_planet1);

    auto magma_cooling = make_shared<Activation>("magma_cooling spinklers");
    redstone_smoke->addStrategy(magma_cooling);
    orangestone_smoke->addStrategy(magma_cooling);

    motion_planet2->addStrategy(peacekeeping_warning);
    motion_planet2->addStrategy(scientist_warning);

    auto alarm_planet2 = std::make_shared<Alarm>("LV-426");
    oxygen_sensor->addStrategy(alarm_planet2);

    auto fire = make_shared<Mail>("alert", "fire fighters");
    smoke_dweezil->addStrategy(fire);
    smoke_moon->addStrategy(fire);

    auto eggs= make_shared<Mail>("alert", "us (the eggs are hatching");


    twig->overviewSensors();
    cout << "----------------TEST 1-----------------" << endl;
    ++*oxygen_sensor;
    ++*sensor_planet1;
    cout << "----------------TEST 1 :   RESULTS-----------------" << endl;
    twig->testAllByLocationPointer(Galaxy);
    --*oxygen_sensor;
    --*sensor_planet1;

    cout << "----------------TEST 2-----------------" << endl;

    twig->activateAllByLocationPointer(planet1);

    cout << "----------------TEST 2 :   RESULTS-----------------" << endl;
    twig->testAllByLocationPointer(Galaxy);

    cout << "----------------TEST 3-----------------" << endl;

    twig->deActivateAllByLocationPointer(planet2);

    cout << "----------------TEST 3 :   RESULTS-----------------" << endl;
    twig->testAllByLocationPointer(planet2);
    twig->overviewByLocationPointer(planet2);

    cout << "----------------TEST 4-----------------" << endl;

    twig->activateAllByLocationPointer(planet2);

    cout << "----------------TEST 4 :   RESULTS-----------------" << endl;
    twig->testAllByLocationPointer(planet2);
    cout << "------------------------------------------------------" << endl;
    twig->testAllByLocationPointer(Moon_unit);
    cout << "------------------------------------------------------" << endl;
    twig->testAllByLocationPointer(Dweezil);

    cout << "----------------TEST 5-----------------" << endl;
    twig->overviewSensors();
    cout << "end of program" << endl;
    return 0;



    /*
    auto *GTCenter = EmergencyCenter::getInstance();
    Location GT{"Group T"};
    Location labChem{"Lab Chemistry 5.01"};
    Location labElec1{"Lab Electronics 10.01"};
    Location labElec2{"Lab Electronics 10.02"};
    Location kitchen{"Alma kitchen"};
    SmokeSensor sensor1{"Sensor Solution", "Lab Chemistry 5.01"};
    GasSensor sensor2{"GasSense", "Lab Chemistry 5.01"};
    SmokeSensor sensor3{"Sensor Solution", "Lab Electronics 10.01"};
    MotionSensor sensor4{"GotYou", "Lab Electronics 10.01", 22, 7};
    MotionSensor sensor5{"GotYou", "Lab Electronics 10.02", 22, 7};
    SmokeSensor sensor6{"Kitchensafe", "Alma kitchen"};
    GasSensor sensor7{"KitchenSafe", "Alma kitchen"};
    MotionSensor sensor8{"BigBrother Is Watching You", "Alma kitchen"};

    GTCenter->add(make_shared<Location>(GT));

    twig->addLocation(make_shared<Location>(Galaxy));
    twig->addChildToParent(make_shared<Location>(Galaxy), make_shared<Sensor>(sensor1));
    GTCenter->addChildToParent(make_shared<Location>(GT), make_shared<Location>(labChem));
    GTCenter->add(make_shared<Location>(labChem));
    GTCenter->addChildToParent(make_shared<Location>(labChem), make_shared<Sensor>(sensor1));
    GTCenter->addChildToParent(make_shared<Location>(labChem), make_shared<Sensor>(sensor2));
    twig->addLocation(make_shared<Location>(Galaxy));
    twig->addChildToParent(make_shared<Location>(Galaxy), make_shared<Sensor>(sensor_twig));

    Alarm alarmChem1{"building"};
    Contact messageChem{"KULeuven central dispatch"};
    Alarm alarmChem2{"Lab Chemistry 5.01"};

    sensor1.addStrategy(make_shared<Alarm>(alarmChem1));

    twig->addChildToParent(make_shared<Location>(Galaxy), make_shared<Location>(planet2));

    twig->addChildToParent(make_shared<Location>(planet1), make_shared<Location>(orange_volcano));
    twig->addChildToParent(make_shared<Location>(planet1), make_shared<Location>(red_volcano));
    twig->addChildToParent(make_shared<Location>(orange_volcano), make_shared<Sensor>(orangestone_smoke));
    twig->addChildToParent(make_shared<Location>(red_volcano), make_shared<Sensor>(redstone_smoke));
    GTCenter->addLocation(make_shared<Location>(labElec1));
    GTCenter->addChildToParent(make_shared<Location>(GT), make_shared<Location>(labElec1));
    GTCenter->addChildToParent(make_shared<Location>(labElec1), make_shared<Sensor>(sensor3));
    GTCenter->addChildToParent(make_shared<Location>(labElec1), make_shared<Sensor>(sensor4));
    twig->addChildToParent(make_shared<Location>(planet1), make_shared<Location>(orange_volcano));
    twig->addChildToParent(make_shared<Location>(planet1), make_shared<Location>(red_volcano));
    twig->addChildToParent(make_shared<Location>(planet2), make_shared<Sensor>(sensor_oxygen));

    twig->addChildToParent(make_shared<Location>(orange_volcano), make_shared<Sensor>(orangestone_smoke));
    twig->addChildToParent(make_shared<Location>(red_volcano), make_shared<Sensor>(redstone_smoke));
    //twig->overviewSensors();
    twig->overviewByLocation("twig galaxy");

    twig->addChildToParent(make_shared<Location>(Galaxy), make_shared<Location>(planet2));
    twig->addChildToParent(make_shared<Location>(planet2), make_shared<Sensor>(sensor3));
    twig->overviewSensors();
    //twig->overviewByLocation("LV-426");
    cout << "end of program" << endl;
    return 0;

    GTCenter->add(make_shared<Location>(labElec2));
    GTCenter->addChildToParent(make_shared<Location>(GT), make_shared<Location>(labElec2));
    GTCenter->addChildToParent(make_shared<Location>(labElec2), make_shared<Sensor>(sensor5));
    twig->addChildToParent(make_shared<Location>(Galaxy), make_shared<Location>(planet2));
    twig->addChildToParent(make_shared<Location>(planet2), make_shared<Sensor>(sensor3));
    //twig->overviewByLocation("LV-426");
    cout << "end of program" << endl;
    return 0;


    GTCenter->add(make_shared<Location>(kitchen));
    GTCenter->addChildToParent(make_shared<Location>(GT), make_shared<Location>(kitchen));
    GTCenter->addChildToParent(make_shared<Location>(kitchen), make_shared<Sensor>(sensor6));
    GTCenter->addChildToParent(make_shared<Location>(kitchen), make_shared<Sensor>(sensor7));
    GTCenter->addChildToParent(make_shared<Location>(kitchen), make_shared<Sensor>(sensor8));
    */

    /*
     ************************************************************ SCENARIO 2 - Louise ************************************************************
     */
/*
    auto* instanceEmergencyCenter = EmergencyCenter::getInstance();

    auto residentialArea = make_shared<Location>("Residential Area");
    auto house1 = make_shared<Location>("House of John and Vicky");
    auto shed = make_shared<Location>("Shed of John");
    auto kitchen = make_shared<Location>("Kitchen of Vicky");
    auto house2 = make_shared<Location>("House of Dave");
    auto livingRoom = make_shared<Location>("Living room of Dave");
    auto house3 = make_shared<Location>("House of Kaitlin");
    auto lab = make_shared<Location>("Lab of Kaitlin");
*/

    //TODO: change the share pointer to the specific sensor it is.
    //TODO: change the sensor classes to have a constructor that also includes the type of sensor

    /*
     * Initializing Sensors
     */
    /*
    auto smokeSensor1 = std::make_shared<Sensor>("Smokey", "John's shed");
    auto motionSensor1 = std::make_shared<Sensor>("IcanCU", "John's shed");
    auto smokeSensor2 = std::make_shared<Sensor>("Smokey", "Vicky's kitchen");
    auto motionSensor2 = std::make_shared<Sensor>("IcanCU", "Vicky's kitchen");
    auto gasSensor1 = std::make_shared<Sensor>("BreatheLabs", "Dave's living room");
    auto smokeSensor3 = std::make_shared<Sensor>("BurningInc", "Dave's living room");
    auto gasSensor2 = std::make_shared<Sensor>("TN2S", "Kaitlin's house");
    auto motionSensor3 = std::make_shared<Sensor>("IcanCU", "Kaitlin's lab");

    //TODO: configure the alarms per sensor location

*/
    /*
     * Building the heirarchy - adding locations and sensors to a locations
     */
 /*
    instanceEmergencyCenter->add(residentialArea);

    instanceEmergencyCenter->addChildToParent(residentialArea, house1);
    instanceEmergencyCenter->addChildToParent(house1, shed);
    instanceEmergencyCenter->addChildToParent(shed, smokeSensor1);
    instanceEmergencyCenter->addChildToParent(shed, motionSensor1);
    instanceEmergencyCenter->addChildToParent(house1, kitchen);
    instanceEmergencyCenter->addChildToParent(kitchen, smokeSensor2);
    instanceEmergencyCenter->addChildToParent(kitchen, motionSensor2);


    instanceEmergencyCenter->addChildToParent(residentialArea, house2);
    instanceEmergencyCenter->addChildToParent(house2, livingRoom);
    instanceEmergencyCenter->addChildToParent(livingRoom, gasSensor1);
    instanceEmergencyCenter->addChildToParent(livingRoom, smokeSensor3);

    instanceEmergencyCenter->addChildToParent(residentialArea, house3);
    instanceEmergencyCenter->addChildToParent(house3, gasSensor2);
    instanceEmergencyCenter->addChildToParent(house3, lab);
    instanceEmergencyCenter->addChildToParent(lab, motionSensor3);



    instanceEmergencyCenter->overviewSensors();
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByLocation("John's shed");
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByLocation("Vicky's kitchen");
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByLocation("Dave's living room");
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByLocation("Kaitlin's house");
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByLocation("Kaitlin's lab");
    //cout<< "******" <<endl;
    //instanceEmergencyCenter->overviewByVendor("IcanCU");
*/
    /*
    cout<< "------------------------ TEST 1 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocation("John's shed");

    //--- Start of code to be tested ---
    ++*smokeSensor1;
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocation("John's shed");

    cout<< "------------------------ TEST 2 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(house1);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->activateAllByLocationPointer(house1);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(house1);

    cout<< "------------------------ TEST 3 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(residentialArea);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 4 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->activateAllComponents();
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 5 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(residentialArea);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 6 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->testAllByLocationPointer(house3);
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);

    cout<< "------------------------ TEST 7 -----------------------" << endl;
    cout<< "------ Before ------" << endl;
    instanceEmergencyCenter->overviewByLocationPointer(residentialArea);


    cout<< "------ Test Output ------" << endl;
    //--- Start of code to be tested ---
    instanceEmergencyCenter->overviewSensorsInVector(instanceEmergencyCenter->orderByLocation(instanceEmergencyCenter->getSensorList()));
    //--- End of code to be tested ---

    cout<< "------ After ------" << endl;




    cout << "end of program" << endl;
    return 0;
    */
}
