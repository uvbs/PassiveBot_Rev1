colorencode_updateInterval = 1.0
colorencode_sinceLastUpdate = 10.0
command=18923746.923874
exec_status=18923746.923874
result=18923746.923874
events=18923746.923874

command_string_max_length=1024

INJECTED=1000
LOGOUT=1.0
PLAYER_NAME=2.0
SCREENSHOTQUESTMAP=50.0
CLEAR_TRIGGERED_EVENTS=100
EVENTS_FOUND=101
WaitingForEvent_GOSSIP_SHOW =100
WaitingForEvent_QUEST_DETAIL = 102

local buffer=""

status_list={}
status_list["string_injected"]=false
status_list["new_command"]=false
status_list["active_waitings"]=false

waitings={}

ffrr=nil

triggered_events={}
is_injected=false

function OnEvent(self, event)
    if is_injected ==false then
        return 
    end
    if event=="QUEST_DETAIL" then
        triggered_events["QUEST_DETAIL"]=tostring(GetQuestID())..";;"..GetTitleText()
    elseif event=="GOSSIP_SHOW" then
        local str=""
        for i = 1, select("#", GetGossipAvailableQuests()) do
            local v = select(i, GetGossipAvailableQuests())
            if i==1 then
                str=str..tostring(v)
            else
                str=str..";;"..tostring(v)
            end
        end
        triggered_events["GOSSIP_SHOW"]=str
    end
    local ev_str=""
    for k,v in pairs(triggered_events) do
        local ev=k.."["..v.."]"
        ev_str=ev_str..ev
    end
    events=ev_str
    print(events)
    
end

-----initialization-------------

function InitStrings()
	buffer_start="BASSIVEPOTBUFFERSTART"
	for i=1,command_string_max_length-buffer_start:len() do 
		buffer=buffer.."B" 
	end
	buffer=buffer_start..buffer
	MagickString:Hide()
	ResultString:Hide()
	MagickString:SetText(buffer)
	SetResult__NoTasks()
end
--------------------------------

----Help functions--------------

function split(str,sep)
   local sep, fields = sep or ":", {}
   local pattern = string.format("([^%s]+)", sep)
   str:gsub(pattern, function(c) fields[#fields+1] = c end)
   return fields
end

--------------------------------

function onload(self)
	
	InitStrings()

	
    print(GetAddOnMetadata("TestAddon", "Title") .. " v" .. GetAddOnMetadata("TestAddon", "Version") .. " loaded");
    TestAddon_MainFrame:RegisterEvent("GOSSIP_SHOW")
    TestAddon_MainFrame:RegisterEvent("QUEST_DETAIL")
    TestAddon_MainFrame:SetScript("OnEvent", OnEvent)
    print(command)
    print(exec_status)
    print(result)
end

function ProcessCommand(self)
    TestAddon_MainFrame_xCoorNum:SetText(command)
    if command == LOGOUT then
        result=1
        command=0
        exec_status=1
        Logout()
    elseif command == PLAYER_NAME then
        result = UnitName("player");
        command=0
        exec_status=1
    elseif command == CLEAR_TRIGGERED_EVENTS then
		
        events="None"
        triggered_events={}
        command=0
        result=1
        exec_status=1
    elseif command == INJECTED then 
        events="None"
        is_injected=true
        command=0
        result=1
        exec_status=1
	
	elseif command== SCREENSHOTQUESTMAP then
	
	
    end
	
	if status_list["new_command"]==true then
		print("new command")
		StartHandleCommand()
		status_list["new_command"]=false
	end
	
	if status_list["active_waitings"]==true and #waitings==0 then
		SetResult__Done()
	end
end

--------------
function SetResult__NoTasks()
	SetResult("NoTasks")
end
function SetResult__InProcess()
	SetResult("InProcess")
end

function SetResult__Success()
	SetResult("Success")
end

function SetResult__Done()
	SetResult("Done")
end

function SetResult__WrongCommandString()
	SetResult("WrongCommandString")
end

function SetResult(result)
	ResultString:SetText(CreateCommString(result))
end
--------------

function ParseCommand(cmd)
	local command_fields=split(cmd, " ")
	if #command_fields ==0 then 
	
	end
	local params={}
	local command=command_fields[1]
	table.remove(command_fields,1)
	return command, command_fields
end 

function CreateCommString(message)
	length=message:len()
	return tostring(length)..";"..message..";"..tostring(length)
end

function StartHandleCommand()
	SetResult__InProcess()
	HandleStringCommand(ReadComString())
end

function ExecuteCommand(cmd_str)
	local cmd, params=ParseCommand(cmd_str)
	for k,v in pairs(params) do
		local n=tonumber(v)
		if n~=nil then
			params[k]=n
		else
			local plen=v:len()
			params[k]=v:sub(2,plen-1)
		end
	end
	result=_G[cmd](unpack(params))
	return result
end
function HandleStringCommand(cmd)
	result=ExecuteCommand(cmd)
	if result~=nil then
		SetResult(result)
	end
end

function test(name, id)
	print("name: "..name)
	print("id: "..id)
	SetResult__Done()
end

function execute_codestring(code_str)
	loadstring(code_str)()
end

function onclick(self, elapsed)
	ffrr= GetMouseFocus()
    exec_status=921874.9238276
    result=921874.8276923
    command=874921.8276923
    events=47321.8764545
	function replace_char(pos, str, r)
		return str:sub(1, pos-1) .. r .. str:sub(pos+1)
	end
    --GetQuestPOIBlobCount(14456)
    --print("click")
    --WorldMapButton =find_frame(self,"QuestMapFrame")
    --WorldMapButton:IsShown()
    --print(WorldMapButton:GetName())
    --GetChildFrames(self,WorldMapButton)
    --print(WorldMapButton:GetName())
end


function ReadComString()
	local function _Read ()
		str=MagickString:GetText()
		if str:len()~=command_string_max_length then
			return nil
		end
		i=1
		while (str:sub(i,i)~=";" and i<=command_string_max_length) do
			i=i+1
		end
		string_start=i
		if i>command_string_max_length then
			return nil
		end
		string_length=tonumber(str:sub(1,string_start-1))
		if string_length==nil then
			return nil
		end
		string_end=string_start+string_length
		if string_end>command_string_max_length then
			return nil
		end
		if string_end+3>command_string_max_length then
			return nil
		end
		string_terminator=str:sub(string_end+1,string_end+3)
		if string_terminator~="[!]" then
			return nil
		end
		real_string=str:sub(string_start+1,string_end)
		if real_string:len() ~=string_length then
			return nil
		end
		return real_string
	end
	result=_Read()
	if result==nil then 
		SetResult__WrongCommandString()
	end
	return result
		
end

function ConfirmStringInjection()
	str=ReadComString()
	if str=="GreetingFromBassivePot" then
		status_list["string_injected"]=true
	end
end

function ConfirmNewCommand()
	if status_list["new_command"]==false then
		status_list["new_command"]=true
	end
end

function Wait(seconds)
	start=GetTime()
	while GetTime()-start<seconds do
	end

end


function ClickOnButtonFrame(frame)
	handler = frame:GetScript("OnClick")
	handler(frame)
end

function CallObjectHandler(object, name)
	handler = object:GetScript(name)
	handler(object)
end


local waitTable = {};
local waitFrame = nil;


function wait(delay, func, ...)

  if(type(delay)~="number" or type(func)~="function") then
    return false;
  end
  if(waitFrame == nil) then
    waitFrame = CreateFrame("Frame","WaitFrame", UIParent);
    waitFrame:SetScript("onUpdate",function (self,elapse)
      local count = #waitTable;
      local i = 1;
      while(i<=count) do
        local waitRecord = tremove(waitTable,i);
        local d = tremove(waitRecord,1);
        local f = tremove(waitRecord,1);
        local p = tremove(waitRecord,1);
        if(d>elapse) then
          tinsert(waitTable,i,{d-elapse,f,p});
          i = i + 1;
        else
          count = count - 1;
          f(unpack(p));
        end
      end
    end);
  end
  tinsert(waitTable,{delay,func,{...}});
  return true;
end


function TakeQuestMapScreenshots(quest_info)
	function get_quest_button_by_id(id)
		for key, val in pairs(QuestScrollFrame.Contents.Titles) do
			if val.questID==id then
				return val
			end
		end
		return nil
	end
	if type(quest_info)=="number" then
		quest_id=quest_info
		questLogIndex = GetQuestLogIndexByID(quest_id);
		quest_button=get_quest_button_by_id(quest_id)
		if quest_button==nil then
			min_diff=99999
			closest_header=QuestScrollFrame.Contents.Headers[1]
			for key, val in pairs(QuestScrollFrame.Contents.Headers) do
				index_diff=val.questLogIndex-questLogIndex
				if index_diff<min_diff then 
					min_diff=index_diff
					closest_header=val
				end
			end
			ClickOnButtonFrame(closest_header)
			quest_button=get_quest_button_by_id(quest_id)
		end
		ClickOnButtonFrame(quest_button)
		Screenshot()
		wait_with_info(1,CallObjectHandler,"wait1",quest_button, "OnEnter")
		wait_with_info(2,Screenshot, "wait2")	
	end
end


function wait_with_info(delay, func,wait_name,...)
	waitings[wait_name]=wait_name
	status_list["active_waitings"]=true
	wait(delay,wait_function,func,wait_name, ...)

end

function wait_function(func, wait_name,...)
	func(...)
	waitings[wait_name]=nil
end



function find_frame(self, fname)
    local frame = EnumerateFrames(self)
    while frame do
        local name=frame:GetName()
        if name == fname then
            TestAddon_MainFrame_xCoorNum:SetText(name)     
            return frame
        

            
        end
        frame = EnumerateFrames(frame)
    end

end


function enum_all_frames(self)
    print("enum")
    frame = EnumerateFrames()
    
    while frame do
        t=frame:GetName()
        print(t)
        frame = EnumerateFrames(frame)
    end
    --get_children(frame)
    

end






function GetChildFrames(self,frame)
    print(frame:GetNumPoints())
    if frame:GetNumChildren() > 0 then
        for i = 1, select("#", frame:GetChildren()) do
            local fr = select(i, frame:GetChildren())
            GetChildFrames(self,fr)
        end
    end 
end


function onclick2(self, elapsed)
    command=18923746.923874
	exec_status=18923746.923874
	result=18923746.923874
	events=18923746.923874
	TakeQuestMapScreenshots(25170)
	--print("=====")
	for key,value in pairs(getmetatable(QuestScrollFrame.Contents.Headers[1]).__index) do
		--print("found member " .. key..": "..tostring(value));
	end
	
	--print(QuestScrollFrame)
	--print(QuestScrollFrame.Contents.Headers[3]:GetTop())
	--print(QuestScrollFrame.Contents.Headers[3]:GetBottom())
	--handler = QuestScrollFrame.Contents.Titles[4]:GetScript("OnEnter")
	--handler(QuestScrollFrame.Contents.Titles[4])
	--handler = QuestScrollFrame.Contents.Titles[4]:GetScript("OnLeave")
	--handler(QuestScrollFrame.Contents.Titles[4])
	--print("=====")
	--b=MagickString:GetText()
	--print(b)
	--print(b:sub(1,1))
	--print(b:sub(1024,1024))
 
end


function onupdate(self, elapsed)
    --print(command)
    ProcessCommand(self)
	
	for k,v in pairs(waitings) do
		print(k)
	end
    --print(TestAddon_MainFrame.waitings)
    --GetChildFrames(self,frm)
    --TestAddon_MainFrame_xCoorNum:SetText()
    
end

function mouse_on_frame(self)


end



function get_children(frame)
    print("Frame: "..frame:GetName())
    if frame:GetNumChildren() > 0 then
        for i = 1, select("#", frame:GetChildren()) do
            local fr = select(i, frame:GetChildren())
            if fr then
                get_children(fr)
            end
        end
    end

    if frame:GetNumRegions()> 0 then
        for i = 1, select("#", frame:GetRegions()) do
            
            local region = select(i, frame:GetRegions())
			print(frame:GetName().." "..tostring(region))
            if region then
				
                if region:GetObjectType() == "FontString" then
                    a=1111.2222
                    print("    Region: "..region:GetText())
                    print(region)
                end
            end
        end
    end
    
end
			
function updateCoor()
	


end