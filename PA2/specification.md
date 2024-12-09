# Specification Document

The following contains in-depth information on specific features of the Watershed Management System.

## Data Structures

### 1. **WaterBody Class**

**Purpose**:
To represent a water body (river, stream, lake) in the watershed system, maintaining its properties and relationships with other water bodies.

**Assumptions**:
* Each water body has a unique name
* Water bodies can be connected in a binary tree structure
* A water body can have dams associated with it

**Inputs**:
* Name (string)
* Type (string: "river" or "stream")
* Length (double, in kilometers)
* Basin size (double, in square kilometers)
* Average discharge (double, in cubic meters per second)
* Dam information (vector of Dam objects)

**State Changes**:
* Pointers to left and right tributaries can be modified
* Parent pointer can be updated
* Dam information can be added or modified

**Cases & Expected Behavior**:
* **New water body creation**: Initialize with empty/default values
* **Copy construction**: Deep copy of all properties except pointers
* **JSON serialization**: Converts to/from JSON format preserving structure
* **Display**: Shows all relevant information including connections

### 2. **Dam Struct**

**Purpose**:
To store information about dams associated with water bodies.

**Assumptions**:
* Each dam has a unique name within its water body
* Capacity is measured in MW

**Inputs**:
* Name (string)
* Year built (integer)
* Capacity (double, in MW)

**Outputs**:
* JSON representation of dam data
* Display information through water body

**State Changes**:
* Properties can be modified through JSON deserialization
* No dynamic memory management required

## Navigation & Operations

### 1. **Tree Navigation**

**Purpose**:
To allow users to traverse the watershed structure and inspect water bodies.

**Assumptions**:
* Tree is properly initialized
* All parent/child relationships are correctly set

**Inputs**:
* User commands (1-4 for navigation choices)

**Outputs**:
* Current water body information
* Navigation options
* Success/failure messages

**Cases & Expected Behavior**:
* **Left/Right Navigation**: Moves to tributary if available
* **Parent Navigation**: Moves up the tree if not at root
* **Exit**: Returns to main menu
* **Invalid Input**: Displays error message and re-prompts

### 2. **Adding Water Bodies**

**Purpose**:
To add new water bodies to the watershed structure.

**Assumptions**:
* Valid input will be provided for required fields
* Proper memory allocation is possible

**Inputs**:
* Water body details (name, type, measurements)
* Position choice (left/right tributary)

**State Changes**:
* Tree structure is modified
* New memory is allocated
* Pointers are updated

**Cases & Expected Behavior**:
* **Empty Tree**: Creates root node
* **Adding Tributary**: Creates new node and updates connections
* **Invalid Input**: Re-prompts user
* **Memory Failure**: Displays error message

### 3. **File Operations**

**Purpose**:
To construct watershed data to and from JSON files.

**Assumptions**:
* File system is accessible
* JSON format is valid

**Inputs**:
* Filename for save/load operations
* JSON-formatted data (for loading)

**Outputs**:
* Success/failure status
* JSON file (when saving)

**State Changes**:
* Tree structure may be completely rebuilt on load
* Existing data is cleared before loading

**Cases & Expected Behavior**:
* **Successful Load**: Tree is populated with file data
* **Failed Load**: Error message, tree remains unchanged
* **Successful Save**: Data written to file
* **Failed Save**: Error message, file unchanged