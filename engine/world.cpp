#include "world.h"

World::World() {
    entities = {};
}

std::vector<Entity> World::getWorldState() {
    return World::entities;
}

void World::tick(float time) {
    std::vector<Entity> entities = World::getWorldState();
    for (Entity entity : entities) {
        entity.x += entity.vx * time;
        entity.y += entity.vy * time;
    }
}

void World::applyInput(int elementId, float dx, float dy) {
    // finding the element
    Entity elementFound;
    std::vector<Entity> entities = World::getWorldState();
    bool found = false;

    for (Entity entity : entities) {
        if (entity.id == elementId) {
            elementFound = entity;
            found = true;
            break;
        }
    }

    if (!found) return;

    elementFound.vx = dx;
    elementFound.vy = dy;
}

