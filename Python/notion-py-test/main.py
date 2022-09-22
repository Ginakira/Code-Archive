from typing import Callable
from notion_client import Client
from pprint import pprint

API_TOKEN = "secret_JkxlrFsIPT2O81IbBMaxqV01E43p8M0DcZ3fttGIQkV"
DATABASE_ID = "26246846-1562-467a-9443-904ee63ad154"
TOKEN_V2 = "89eca17d082423903e509c44970a374b32601c1a499a1f3b3b02c3d5c908cbc5e6adb91d11a643cfd34c2caf12e3338487987334790bc1e2b6186c305f1c35411e83225c5cb0f302672335a8ead5"

DATABASE_URL = "https://www.notion.so/ginakira/262468461562467a9443904ee63ad154?v=8ea5663508504311829907da44b2a6ee"

notion = Client(auth=API_TOKEN)


def text_type_getter(f: Callable):

    def _func(props_item):
        text = ""
        try:
            text = f(props_item)
        except (KeyError, IndexError):
            text = "无"
        return text

    return lambda props_item: _func(props_item=props_item)


get_plain_text = text_type_getter(lambda p: p["rich_text"][0]["plain_text"])
get_select_name = text_type_getter(lambda p: p["select"]["name"])


def main():
    resp = notion.databases.query(database_id=DATABASE_ID,
                                  filter={
                                      "and": [{
                                          "property": "文件名",
                                          "rich_text": {
                                              "equals": "ytb220920"
                                          },
                                      }]
                                  })

    if not resp or not len(resp["results"]):
        print("Empty response")
        return

    result = resp["results"][0]
    props = result["properties"]
    pprint(props)

    file_name = props["文件名"]["title"][0]["plain_text"]
    series_name = props["系列名"]["select"]["name"]
    total_time = get_plain_text(props["时长"])
    translator = get_plain_text(props["翻译"])
    translate_status = get_select_name(props["翻译状态"])
    timeliner = get_plain_text(props["时轴"])
    timeliner_status = get_select_name(props["时轴状态"])
    corrector = get_plain_text(props["校对"])
    corrector_status = get_select_name(props["校对状态"])
    task_staus = get_select_name(props["任务状态"])
    bvid = get_plain_text(props["BV号"])
    publish_account = get_select_name(props["发布账号"])
    publish_date = props["发布日期"]["date"]["start"]

    info_text = f"任务名：{file_name}\n"\
                f"状态：{task_staus}\n"\
                f"系列名：{series_name}\n"\
                f"时长：{total_time}\n"\
                f"翻译：{translator}（{translate_status}）\n"\
                f"时轴：{timeliner}（{timeliner_status}）\n"\
                f"校对：{corrector}（{corrector_status}）\n"\
                f"发布帐号：{publish_account}\n"\
                f"发布日期：{publish_date}\n"\

    print(info_text)


if __name__ == "__main__":
    main()