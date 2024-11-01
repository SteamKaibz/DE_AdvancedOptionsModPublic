# DE Advanced Options Mod


## Project Description
This is the source for DE Advanced Options Mod:  https://www.nexusmods.com/doometernal/mods/1255


## Prerequisites
- Visual Studio 2022 or later
- Optional: CommentsPlus17 extension (extra formatting/colors for comments) https://marketplace.visualstudio.com/items?itemName=mhoumann.CommentsPlusDev17Preview


## How to Build

1. **Clone the repository**:
   ```bash
   git clone https://github.com/SteamKaibz/DE_AdvancedOptionsModPublic.git
   ```

2. **Open the solution**:
   Open the `.sln` file in Visual Studio.

3. **Set up Precompiled Headers**:
   - In Solution Explorer -> Right-click on the project -> Properties
   - Navigate to **C/C++** -> **Precompiled Headers**
   - Set it to **Not Using Precompiled Headers**

4. **Set the Target Name**:
   - In Solution Explorer -> Right-click on the project -> Properties
   - Navigate to **General** -> **Target Name**
   - Ensure it's set to `msimg32`

5. **Select Configuration**:
   - Use the drop-down in the toolbar to select either `Vanilla` or `Sandbox` or any other configuration you want from the Solution Configuration. (the configurations with Dev_ will give acces to shortcut in the game to display or test certain features. The configs with Debug_ prefix will use default Debug settings and will have more safety nets for ex for the isbarPtr() function)

6. **Build the Project**:
   - Press `Ctrl + Shift + B` or go to `Build` -> `Build Solution`.


## Usage Instructions
See the instructions on the nexus page for detailed information on how to install/use the mod.


## How to generate game data (classes, enums, events...)
I would recommend using meathook mod https://github.com/brongo/m3337ho0o0ok/releases and use the available commands to generate what you need.


## Contribution Guidelines
Contributions and Pull Requests are welcome! 
For major changes, please open an issue first to discuss what you would like to change.


## License
This project is licensed under the BSD-2-Clause license.


## Acknowledgments
- [UniversalHookX](https://github.com/bruhmoment21/UniversalHookX) - Used for Imgui implementation
- [MinHook](https://github.com/TsudaKageyu/minhook) - Used for functions hooking
- [nlohmann Json](https://github.com/nlohmann/json) - Json library

- Thanks to https://github.com/belazr for UniversalHook fixes and general contributions.
- Thanks to https://github.com/Decimation for advices and improvements.
- Thanks to MethanHydrat for getting me into modding and his work/advices.
- Thanks to SamPt for his advices/feedback.
- Thanks to Chrispy for his work on Meathook mod.
- Thanks to Sunbeam for all the knowledge he shared;
