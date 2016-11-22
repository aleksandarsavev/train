import datetime
import os.path

def log(msg):
    now = datetime.datetime.now()
    now_str = now.strftime("%Y-%m-%d %H:%M:%S")
    print("[" + now_str + "] " + msg)

if __name__ == "__main__":
    now = datetime.datetime.now()
    today_str = now.strftime("%Y-%m-%d")

    log("Today is: " + today_str)
    log("Searching for file '" + today_str + "' in the current directory...")
    exists = os.path.isfile(today_str)
    log("File '" + today_str + "' was " + ("not " if not exists else "") + "found.")

    with open(today_str, 'a', encoding='utf-8') as f:
        if not exists:
            f.write(today_str + "\n")
            log("File '" + today_str + "' was created in the current directory.")

        import tempfile
        from subprocess import call
        EDITOR = os.environ.get('EDITOR', 'vim')

        initial_message = ""
        edited_message = ""

        with tempfile.NamedTemporaryFile(mode='w+', encoding='utf-8', suffix=".tmp") as tf:
            tf.write(initial_message)
            tf.flush()
            log("Temporary file '" + tf.name + "' was created.")
            log("Opening text editor '" + EDITOR + "'...")
            call([EDITOR, tf.name])
            log("Text editor '" + EDITOR + "' was closed.")
            tf.seek(0)
            edited_message = tf.read().strip()

        if len(edited_message) > 0:
            time_str = now.strftime("%H:%M")
            f.write("\n") # single empty line between notes
            f.write(time_str + "\n")
            f.write(edited_message + "\n")
            log("The note '" + time_str + "' was added to the file '" + today_str + "'.")
        else:
            log("Note is empty. Nothing was added to the file.")
