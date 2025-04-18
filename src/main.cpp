#include "app-window.h"

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

    // Handle window closing ...
    ui->on_quit([&] -> void { ui->window().dispatch_close_requested_event(); });

    // Handle minimize window action
    ui->on_window_minimized([&](const bool enabled) -> void { ui->window().set_minimized(enabled); });

    // Handle minimize window action
    ui->on_window_maximized([&](const bool enabled) -> void { ui->window().set_maximized(enabled); });

    ui->on_window_moved([&](const double &dx, const double &dy) -> void
    {
        const auto physical_pos = ui->window().position();
        const auto new_pt = slint::Point<int32_t>(physical_pos.x + dx, physical_pos.y + dy);
        ui->window().set_position(slint::PhysicalPosition(new_pt));
    });

    ui->run();
    return 0;
}
