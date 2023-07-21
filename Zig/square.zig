// zig run square.zig

fn square(x: anytype) @TypeOf(x) {
    return x * x;
}


pub fn main() void {
    const std = @import("std");

    const result = comptime square(2 + 3);
    std.debug.print("{}", .{result});

    return;
}
