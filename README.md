# Setting Up SQLite3 for MinGW on Windows

This guide will help you set up SQLite3 for use with MinGW on Windows, including adding SQLite to the `PATH`, creating the `libsqlite3.a` library, and configuring your project to link against SQLite.

## Step 1: Download SQLite3 for Windows

1. Go to the official [SQLite Download Page](https://www.sqlite.org/download.html).
2. Download the following files:
   - **`sqlite-dll-win-x64-<version>.zip`**: This is the 64-bit DLL for SQLite.
   - **`sqlite-tools-win-x64-<version>.zip`** (Optional): Command-line tools for SQLite (such as `sqlite3.exe`).
3. Extract the contents of **`sqlite-dll-win-x64-<version>.zip`**. You will get:
   - `sqlite3.dll`
   - `sqlite3.def`

## Step 2: Set Up SQLite3

1. **Create a directory** (e.g., `C:\MinGW\sqlite3`) and move `sqlite3.dll` and `sqlite3.def` into this folder.

2. **Add SQLite3 to the system `PATH`**:
   - Open **Control Panel > System > Advanced system settings**.
   - Click **Environment Variables**.
   - In **System variables**, find the `Path` variable and select **Edit**.
   - Click **New** and add the path to your SQLite folder (e.g., `C:\MinGW\sqlite3`).
   - Click **OK** to close all windows and apply the changes.

3. **Verify the changes**:
   - Open a new Command Prompt and type `echo %PATH%` to verify that the SQLite path has been added.
   - You should now be able to run `sqlite3.dll` or any SQLite-related tools from the command line.

## Step 3: Create `libsqlite3.a` for Linking

MinGW uses static or import libraries (`.a` or `.lib`) for linking. If `libsqlite3.a` is not provided, you can create it from the downloaded files.

1. Open **Command Prompt** and navigate to the folder where you extracted `sqlite3.dll` and `sqlite3.def`:
   ```bash
   cd C:\MinGW\sqlite3
