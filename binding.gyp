{
	"targets": [
		{
			"target_name": "addAsync",
			"sources": ["addAsync.cc", "addWorker.cc"],
			"include_dirs": ["<!(node -e \"require('nan')\")"]
		}
	]
}
