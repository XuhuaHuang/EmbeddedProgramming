// zig run .\hello_world.zig

const std = @import("std");

pub fn main() void {
    std.debug.print("Hello, {s}!\n", .{"World"});
    return;
}
