{
	"targets": [
		{
			"target_name": "addAsync",
			"sources": ["addAsync.cc"],
			"include_dirs": ["<!(node -e \"require('nan')\")"]
		}
	]
}
