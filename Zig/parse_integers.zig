// zig test parse_integers.zig

const std = @import("std");
const parseInt = std.fmt.parseInt;

test "parse integers" {
    const input = "123 67 89,99";
    const allocator = std.testing.allocator;

    var list = std.ArrayList(u32).init(allocator);
    // Ensure the list is freed at scope exit.
    defer list.deinit();

    var it = std.mem.tokenize(u8, input, " ,");
    while (it.next()) |num| {
        const n = try parseInt(u32, num, 10);
        try list.append(n);
    }

    const expected = [_]u32{ 123, 67, 89, 99 };

    for (expected, list.items) |exp, actual| {
        try std.testing.expectEqual(exp, actual);
    }
}
