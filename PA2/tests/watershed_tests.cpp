#include "unit_test.hpp"


void testWaterBodyCreation() {
    WaterBody body;
    body.name = "Test River";
    body.type = "river";
    body.length = 100.0;
    body.basinSize = 1000.0;
    body.averageDischarge = 50.0;
    
    ASSERT(body.name == "Test River", "Name not set correctly");
    ASSERT(body.type == "river", "Type not set correctly");
    ASSERT(body.length == 100.0, "Length not set correctly");
    ASSERT(body.basinSize == 1000.0, "Basin size not set correctly");
    ASSERT(body.averageDischarge == 50.0, "Average discharge not set correctly");
    
    results.passed++;
}

void testDamCreation() {
    WaterBody river;
    Dam dam;
    dam.name = "Test Dam";
    dam.yearBuilt = 2000;
    dam.capacity = 500.0;
    
    river.dams.push_back(dam);
    
    ASSERT(river.dams.size() == 1, "Dam not added to water body");
    ASSERT(river.dams[0].name == "Test Dam", "Dam name not set correctly");
    ASSERT(river.dams[0].yearBuilt == 2000, "Dam year not set correctly");
    ASSERT(river.dams[0].capacity == 500.0, "Dam capacity not set correctly");
    
    results.passed++;
}

void testWatershedStructure() {
    WatershedTree watershed;
    
    WaterBody* columbia = new WaterBody();
    columbia->name = "Columbia River";
    columbia->type = "river";
    
    WaterBody* snake = new WaterBody();
    snake->name = "Snake River";
    snake->type = "river";
    
    columbia->right = snake;
    snake->parent = columbia;
    
    ASSERT(columbia->right->name == "Snake River", "Right tributary not set correctly");
    ASSERT(snake->parent->name == "Columbia River", "Parent not set correctly");
    
    delete columbia->right;
    delete columbia;
    
    results.passed++;
}

void testJsonSerialization() {
    WaterBody body;
    body.name = "Test River";
    body.type = "river";
    body.length = 100.0;
    body.basinSize = 1000;
    body.averageDischarge = 50;
    
    Dam dam;
    dam.name = "Test Dam";
    dam.yearBuilt = 2000;
    dam.capacity = 500.0;
    body.dams.push_back(dam);
    
    json j = body.to_json();
    
    ASSERT(j["name"] == "Test River", "JSON serialization failed for name");
    ASSERT(j["type"] == "river", "JSON serialization failed for type");
    ASSERT(j["length"] == 100.0, "JSON serialization failed for length");
    ASSERT(j["dams"][0]["name"] == "Test Dam", "JSON serialization failed for dam");
    
    results.passed++;
}

void testJsonDeserialization() {
    json j = {
        {"name", "Test River"},
        {"type", "river"},
        {"length", 100.0},
        {"basinSize", 1000.0},
        {"averageDischarge", 50.0},
        {"dams", {{
            {"name", "Test Dam"},
            {"yearBuilt", 2000},
            {"capacity", 500.0}
        }}}
    };
    
    WaterBody body;
    body.from_json(j);
    
    ASSERT(body.name == "Test River", "JSON deserialization failed for name");
    ASSERT(body.type == "river", "JSON deserialization failed for type");
    ASSERT(body.length == 100.0, "JSON deserialization failed for length");
    ASSERT(body.dams[0].name == "Test Dam", "JSON deserialization failed for dam");
    
    results.passed++;
}



