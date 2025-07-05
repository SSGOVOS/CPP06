#include <iostream>
#include "Serialization.hpp"

int main() {
    // Create and initialize a Data object
    Data data = {"Azzeddine", 22};

    // Print original Data pointer and values
    std::cout << "Original Data object:\n";
    std::cout << "Address: " << &data << "\n";
    std::cout <<"Name: " << data.name << ", Value: " << data.age << "\n";

    // Serialize the Data object pointer
    uintptr_t raw = Serialization::serialize(&data);
    std::cout << "\nSerialized uintptr_t: " << raw << "\n";

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserializedData = Serialization::deserialize(raw);

    // Verify the deserialized Data object
    std::cout << "\nDeserialized Data object:\n";
    std::cout << "Address: " << deserializedData << "\n";
    std::cout << "Name: " << deserializedData->name << ", Value: " << deserializedData->age << "\n";

    // Confirm original and deserialized pointers are identical
    if (&data == deserializedData) {
        std::cout << "\nSerialization and deserialization successful!\n";
    } else {
        std::cout << "\nError: Pointer mismatch after deserialization.\n";
    }

    return 0;
}