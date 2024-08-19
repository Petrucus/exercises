
Conversation opened. 1 unread message.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct GameObject {
    int id;
    struct GameObject* next;
} GameObject;

static GameObject* active_objects = NULL;
static GameObject* dead_objects = NULL;

[[nodiscard]] GameObject* create_object(void) {
    GameObject* obj = dead_objects ? dead_objects : malloc(sizeof(GameObject));
    if (obj) {
        if (dead_objects) dead_objects = dead_objects->next;
        obj->next = active_objects;
        active_objects = obj;
    }
    return obj;
}

bool remove_object(GameObject* obj) {
    if (!obj) return false;
    
    GameObject** current = &active_objects;
    while (*current && *current != obj) {
        current = &(*current)->next;
    }
    if (*current) {
        *current = obj->next;
        obj->next = dead_objects;
        dead_objects = obj;
        return true;
    }
    return false;
}

void cleanup(void) {
    GameObject *temp;
    while (active_objects) {
        temp = active_objects;
        active_objects = active_objects->next;
        free(temp);
    }
    while (dead_objects) {
        temp = dead_objects;
        dead_objects = dead_objects->next;
        free(temp);
    }
}

static int count_objects(GameObject* list) {
    int count = 0;
    while (list) {
        count++;
        list = list->next;
    }
    return count;
}


// 1. Create and remove objects: Tests basic creation and removal functionality.
// 2. Reuse dead object: Ensures that dead objects are reused when creating new objects.
// 3. Remove non-existent object: Verifies that trying to remove an object not in the list fails gracefully.
// 4. Remove NULL: Checks that trying to remove a NULL pointer is handled correctly.
// 5. Create object when out of memory: Attempts to create many objects to test behavior when memory allocation might fail.


int main(void) {
    // Test case 1: Create and remove objects
    GameObject* obj1 = create_object();
    GameObject* obj2 = create_object();
    assert(count_objects(active_objects) == 2);
    assert(remove_object(obj1));
    assert(count_objects(active_objects) == 1);
    assert(count_objects(dead_objects) == 1);

    // Test case 2: Reuse dead object
    GameObject* obj3 = create_object();
    assert(obj3 == obj1);  // obj3 should reuse the memory of obj1
    assert(count_objects(active_objects) == 2);
    assert(count_objects(dead_objects) == 0);

    // Test case 3: Remove non-existent object
    GameObject fake_obj = {0};
    assert(!remove_object(&fake_obj));

    // Test case 4: Remove NULL
    assert(!remove_object(NULL));

    // Test case 5: Create object when out of memory
    // This is a bit tricky to test without actually running out of memory,
    // so we'll just create a bunch of objects and make sure it doesn't crash
    for (int i = 0; i < 1000; i++) {
        GameObject* obj = create_object();
        if (!obj) {
            printf("Failed to create object after %d creations\n", i);
            break;
        }
    }

    // Cleanup
    cleanup();
    assert(count_objects(active_objects) == 0);
    assert(count_objects(dead_objects) == 0);

    printf("All tests passed!\n");
    return 0;
}

