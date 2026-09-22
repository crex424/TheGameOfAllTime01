#include <bn_backdrop.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include "bn_sprite_items_dot.h"

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 0, 0));

    auto dot = bn::sprite_items::dot.create_sprite(0, 0);

    bn::fixed speed = 5.5;

    while (true)
    {
        if (bn::keypad::left_held())
        {
            if (dot.x() >= 130)
            {
                dot.set_x(-130);
            }
            else
            {
                dot.set_x(dot.x() - speed);
            }
        }
        if (bn::keypad::right_held())
        {
            if (dot.x() <= -130)
            {
                dot.set_x(130);
            }
            else
            {
                dot.set_x(dot.x() + speed);
            }
        }
        if (bn::keypad::up_held())
        {
            if (dot.y() <= -90)
            {
                dot.set_y(90);
            }
            else
            {
                dot.set_y(dot.y() - speed);
            }
        }
        if (bn::keypad::down_held())
        {
            if (dot.y() >= 90)
            {
                dot.set_y(-90);
            }
            else
            {
                dot.set_y(dot.y() + speed);
            }
        }
        bn::core::update();
    }
}