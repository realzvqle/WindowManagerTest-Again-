

local red = CreateColor(255, 0, 120, 255);
local resd = CreateColor(25, 0, 120, 255);
local ressd = CreateColor(25, 0, 10, 255);

local result = DrawButton("Hi", 100, 100, 30, 30, red, resd, ressd, 30);


if result == 2 then
    CreateTask(L"H", 300, 300)
end
