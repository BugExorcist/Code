-- a = 123
-- print(a)

-- A = "hello world"
-- print(A)

-- -- 注释
-- --[[
--  多行注释
--  多行注释

-- ]]

-- -- 语句嵌套

-- --[[

-- [=[

-- ]=]

-- ]]

-- age = 14
-- if age < 18 then
--     print("you should go to school")
-- elseif age > 70 then
--     print("relax")
-- else
--     print("you can work")
-- end

-- for i = 0, 20, 5 do
--     print("i = " , i)
-- end


-- print("5 / 3 = ", 5 // 3)
-- print("5 ^ 3 = ", 5 ^ 3)

-- age = 30
-- if age >= 18 and age < 65 then
--     print("you can work")
-- end

-- a = 1
-- while a <= 10 do
--     print(a)
--     a = a + 1
-- end

-- a = {1, 2, 3, 4, "a", "b", x = 123, y = 456}

-- for i = 1, 8 do
--     print(a[i])
-- end
-- print(a.x)
-- print(a["y"])


-- pos = {dir = {x = 1, y = 2, ["z"] = 3}}

-- print(pos.dir.x)
-- print(pos.dir.y)
-- print(pos.dir.z)

-- a = {1, 2, 3, 4, "a", "b", x = 123, ["y"] = 456, pos = {z = 789}}

-- for k,v in ipairs(a) do
--     print(k, ":", v)

-- end

-- add = function(a, b)
--     return a + b
-- end



-- function add(a, b)
--     return a + b
-- end

-- function fun1(a, b)
--     return a + b, a * b
-- end
-- sum , mul = fun1(1, 2)


-- function process(f, a, b)
--     print("f:" , f )
--     print("a:" , a )
--     print("b:" , b )

-- end
-- print(sum, mul)

-- function add(...)
--     local sum = 0
--     local srg = {...}
--     for i, v in ipairs(srg) do
--         sum = sum + v
--         print(i, sum)
--     end
-- end

-- add(1,2,3,4,5,6,7,8,9,10)


-- age = 20
-- canVote = age > 18 and true
-- print(canVote)  -- 输出false


-- co = coroutine.create(
--     function(a, b)
--         print("a = ", a, "b = ", b)
--         v1, v2 = coroutine.yield("x", 1)

--         print("a = ", a, "b = ", b)
--         print("v1 = ", v1, "v2 = ", v2)
--         coroutine.yield("x", 2)
--     end
-- )

-- r1, r2, r3 = coroutine.resume(co, 12, 34)
-- print(r1, r2, r3)
-- r1, r2, r3 = coroutine.resume(co, 56, 78)
-- print(r1, r2, r3)


-- local monster = {
--     name = "monster",
--     HP = 100,
--     pos = {x = 0, y = 0},
--     Recover = function(self)
--         self.HP = self.HP + 10
--     end
-- }

-- print(monster.HP)

-- -- monster.TakeDamage = function(self, damage)
-- --     self.HP = self.HP - damage
-- -- end

-- function monster:TakeDamage(damage)
--     self.HP = self.HP - damage
-- end

-- monster.TakeDamage(monster, 10)
-- print(monster.HP)
-- monster:TakeDamage(10)
-- print(monster.HP)

-- local monster1 = monster
-- setmetatable(monster1, monster)
-- monster1:TakeDamage(10)
-- print(monster.HP)
-- print(monster)
-- print(monster1)

-- entity = {}
-- Animals = {
--     name = "animal",
--     talk = function(self, message)
--         print(self.name, "talk:", message)
--     end
-- }
-- Animals.__index = Animals

-- function entity.new()
--     local t = {}
--     setmetatable(t, Animals)
--     return t
-- end

-- nai1 = entity.new()
-- nai1.name = "cat"
-- nai1:talk("meow")
-- nai2 = entity.new()
-- nai2.name = "dog"
-- nai2:talk("wang")

-- Class_Monster = {
--     name = "monster",
--     Hp = 100,
--     Mp = 100,
--     TakeDamage = function(self, damege)
--         self.Hp = self.Hp - damege
--     end,
--     Recover = function(self)
--         self.Hp = self.Hp + 10
--     end,
--     Info = function(self)
--         print(self.name, ": HP:", self.Hp, "Mp", self.Mp)
--     end
-- }
-- Class_Monster.__index = Class_Monster

-- setmetatable(Class_Monster, {
--     __call = function (self, name, hp, mp)
--         return self.new(name, hp, mp)
--     end
-- })

-- function Class_Monster.new(name, hp, mp)
--     local t = {}
--     t.name = name
--     t.Hp = hp
--     t.Mp = mp
--     setmetatable(t, Class_Monster)
--     return t
-- end

-- local zombie = Class_Monster("僵尸", 50, 0)
-- local demon = Class_Monster("恶魔", 100, 100)
-- local bat = Class_Monster("蝙蝠", 20, 20)

-- zombie:Info()
-- demon:Info()
-- bat:Info()
-- print("-----------------")
-- zombie:TakeDamage(10)
-- demon:TakeDamage(20)
-- bat:TakeDamage(5)

-- zombie:Info()
-- demon:Info()
-- bat:Info()
-- print("-----------------")


-- Class_Monster = {
--     name = "monster",
--     Hp = 100,
--     Mp = 100,
--     TakeDamage = function(self, damege)
--         self.Hp = self.Hp - damege
--     end,
--     Recover = function(self)
--         self.Hp = self.Hp + 10
--     end,
--     Info = function(self)
--         print(self.name, ": HP:", self.Hp, "Mp", self.Mp)
--     end
-- }
-- Class_Monster.__index = Class_Monster

-- -- 优化构造语法糖
-- setmetatable(Class_Monster, {
--     __call = function (self, name, hp, mp)
--         return self:new(name, hp, mp)
--     end
-- })

-- -- 相当于构造函数
-- function Class_Monster:new(name, hp, mp)
--     local t = {}
--     t.name = name
--     t.Hp = hp
--     t.Mp = mp
--     setmetatable(t, Class_Monster)
--     return t
-- end

-- local Class_MagicMonster = {
--     description = "可以释放法术的怪兽",
--     Attact = function (self)
--         self.Mp = self.Mp - 10
--         print(self.name, ": 释放技能")
--     end
-- }

-- setmetatable(Class_MagicMonster, {
--     __index = Class_Monster,
--     __call = function (self, name, hp, mp)
--         obj = Class_Monster(name, hp, mp)
--         setmetatable(obj, {__index = Class_MagicMonster})
--         return obj
--     end
-- })

-- -- 多态
-- function Class_MagicMonster:Info()
--     print(self.name, ": HP:", self.Hp, "Mp", self.Mp, "描述:", self.description)
-- end

-- local cm = Class_MagicMonster("小怪兽", 50, 50)
-- cm:Info()


-- function GetPeople()
--     local self = {name = "小王", age = 20, sex = "男"}
--     local function GetName()
--         return self.name
--     end
--     local function IsAdult()
--         return self.age > 18
--     end
--     return {GetName = GetName, IsAdult = IsAdult, sex = self.sex}
-- end

-- local people = GetPeople()
-- print(people:GetName())

Monster = {
    HP = 100,
    Type = "Monster",
    GetHP = function (self)
        return self.HP
    end,
    TakeDamage = function (self, damage)
        self.HP = self.HP - damage
    end,
    SetHP = function (self, hp)
        self.HP = hp
    end
}

function Monster.new()
    local obj = {HP = Monster.HP, Type = Monster.Type} -- 默认值
    setmetatable(obj, Monster)
    -- 定义能被访问的属性
    Monster.__index = {GetHP = Monster.GetHP, TakeDamage = Monster.TakeDamage, Type = Monster.Type}
    -- 拦截属性设置
    Monster.__newindex = function (t, k, v)
        print("设置属性:", k, "值为:", v)
        if (k == "Type") then
            print("无法修改此属性")
            return
        end
        rawset(t, k, v)
    end
    return obj
end

local monster = Monster:new()
--monster:SetHP(999)

